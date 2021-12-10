//
// Created by Asif Islam on 12/4/21.
//

#ifndef P4_3504C_ASIF_MINESWEEPER_H
#define P4_3504C_ASIF_MINESWEEPER_H
#include <SFML/Graphics.hpp>
#include "Toolbox.h"
#include "Tile.h"
#include "Button.h"
#include "MineTile.h"
#include "GameState.h"
#include <iostream>

#endif //P4_3504C_ASIF_MINESWEEPER_H

bool DEBUG_MODE_STATE = false;
void render();
void restart();
void loadTest1Board();
void loadTest2Board();
void toggleDebugMode();
bool getDebugMode();
int gameLoop();

int launch()
{

    Toolbox *tb = Toolbox::getInstance();
    tb->gameState = new GameState("boards/testboard1.brd");
    gameLoop();
    return 0;
};

int gameLoop()
{
    Toolbox *tb = Toolbox::getInstance();

    //Load Game Button textures
    sf::Texture loserFace, happyFace, winnerFace;
    sf::Texture debugTexture;
    sf::Texture test1Texture, test2Texture;
    if (!loserFace.loadFromFile("images/face_lose.png"))
    {
        std::cerr << std::endl;
    }
    if (!happyFace.loadFromFile("images/face_happy.png"))
    {
        std::cerr << std::endl;
    }
    if (!winnerFace.loadFromFile("images/face_win.png"))
    {
        std::cerr << std::endl;
    }
    if (!debugTexture.loadFromFile("images/debug.png"))
    {
        std::cerr << std::endl;
    }
    if (!test1Texture.loadFromFile("images/test_1.png"))
    {
        std::cerr << std::endl;
    }
    if (!test2Texture.loadFromFile("images/test_2.png"))
    {
        std::cerr << std::endl;
    }

    //Create function pointers to pass to buttons
    void (*newGameFunc)() = &restart;
    void (*testGame1Func)() = &loadTest1Board;
    void (*testGame2Func)() = &loadTest2Board;

    //Allocate new Buttons
    tb->newGameButton = new Button(sf::Vector2f(0, 32 * 16), newGameFunc);
    tb->newGameButton->setSprite(new sf::Sprite());
    tb->newGameButton->getSprite()->setTexture(happyFace);

    tb->testButton1 = new Button(sf::Vector2f(32 * 17, 32 * 16), testGame1Func);
    tb->testButton1->setSprite(new sf::Sprite());
    tb->testButton1->getSprite()->setTexture(test1Texture);

    tb->debugButton = new Button(sf::Vector2f(32 * 17, 32 * 16), []() {});
    tb->debugButton->setSprite(new sf::Sprite());
    tb->debugButton->getSprite()->move(sf::Vector2f(-1 * (tb->testButton1->getSprite()->getGlobalBounds().width), 0));
    tb->debugButton->getSprite()->setTexture(debugTexture);

    tb->testButton2 = new Button(sf::Vector2f(32 * 17, 32 * 16), testGame2Func);
    tb->testButton2->setSprite(new sf::Sprite());
    tb->testButton2->getSprite()->move(sf::Vector2f(tb->testButton1->getSprite()->getGlobalBounds().width, 0));
    tb->testButton2->getSprite()->setTexture(test2Texture);

    //Set Game Status
    tb->gameState->setPlayStatus(GameState::PLAYING);

    //Display all elements
    render();

    //Main event loop
    while (tb->window.isOpen())
    {
        sf::Event event;
        while (tb->window.pollEvent(event))
        {
            switch (event.type)
            {
            //Close window
            case sf::Event::Closed:
            {
                tb->window.close();
                break;
            }

            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(tb->window);
                //Handle coordinates if window is resized
                sf::Vector2f mousePosConverted = tb->window.mapPixelToCoords(mousePos);

                //Each tile is a 32 x 32 square, so we can create a cartesian like
                //system of coordinates by dviding by the side length
                unsigned int mouseTileX = (int)mousePosConverted.x / 32;
                unsigned int mouseTileY = (int)mousePosConverted.y / 32;

                //Switch to handle left vs right clicks
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:
                {
                    std::cout << mouseTileX << ", " << mouseTileY << std::endl;
                    Tile *tempTile = tb->gameState->getTile(mouseTileX, mouseTileY);
                    if (!tempTile) //Handle if tile does not exist
                    {
                        //Check the buttons
                        if (tb->newGameButton->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            if (tb->gameState->getPlayStatus() == GameState::LOSS)
                            {
                                tb->newGameButton->getSprite()->setTexture(happyFace);
                            }

                            if (tb->gameState->getPlayStatus() == GameState::WIN)
                            {
                                tb->newGameButton->getSprite()->setTexture(happyFace);
                            }
                            tb->newGameButton->onClick();
                        }

                        if (tb->testButton1->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            tb->testButton1->onClick();
                        }
                        else if (tb->testButton2->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            tb->testButton2->onClick();
                        }
                        else if (tb->debugButton->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            tb->debugButton->onClick();
                        }
                    }
                    else if (tb->gameState->getPlayStatus() == GameState::PLAYING)
                    {
                        tempTile->onClickLeft();

                        bool isWon = false;
                        int numMines = tb->gameState->getMineCount();
                        int tilesNotRevealed = 0;

                        //TODO: Add code to dynamically figure out board dimensions
                        for (int j = 0; j < 16; j++)
                        {
                            for (int i = 0; i < 25; i++)
                            {
                                Tile *currentTile = tb->gameState->getTile(i, j);
                                if (currentTile->getState() != Tile::REVEALED && currentTile->getState() != Tile::EXPLODED)
                                    tilesNotRevealed++;
                            }
                        }

                        if (tilesNotRevealed == numMines)
                        {
                            tb->gameState->setPlayStatus(GameState::WIN);
                            tb->newGameButton->getSprite()->setTexture(winnerFace);
                        };

                        if (tb->gameState->getPlayStatus() == GameState::LOSS)
                        {
                            tb->newGameButton->getSprite()->setTexture(loserFace);
                        }
                    }
                    render();
                    break;
                }
                case sf::Mouse::Right:
                {
                    std::cout << mouseTileX << ", " << mouseTileY << std::endl;
                    Tile *tempTile = tb->gameState->getTile(mouseTileX, mouseTileY);
                    if (!tempTile)
                    {
                        std::cout << "Tile out of bounds" << std::endl;
                    }
                    else
                    {
                        std::cout << "Right\n";
                        tempTile->onClickRight();
                    }
                    render();
                    break;
                }
                default:
                {
                    break;
                }
                }
            }

            default:
            {
                break;
            }
            }
        }
    }

    return 0;
}

//Draw all UI Elements based on GameState
void render()
{
    Toolbox *tb = Toolbox::getInstance();
    tb->window.clear(sf::Color::White);

    //TODO: Add code to dynamically figure out board dimensions
    for (int j = 0; j < 16; j++)
    {
        for (int i = 0; i < 25; i++)
        {
            Tile *currentTile = tb->gameState->getTile(i, j);
            if (getDebugMode() == true)
            {
                
            }
            currentTile->draw();
        }
    }

    tb->window.draw(*tb->debugButton->getSprite());
    tb->window.draw(*tb->testButton1->getSprite());
    tb->window.draw(*tb->testButton2->getSprite());
    tb->window.draw(*tb->newGameButton->getSprite());

    tb->window.display();
}

void restart()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState();
    render();
}

void loadTest1Board()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState("boards/testboard1.brd");
    render();
};

void loadTest2Board()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState("boards/testboard2.brd");
    render();
};

bool getDebugMode()
{
    return DEBUG_MODE_STATE;
};

void toggleDebugMode()
{
    DEBUG_MODE_STATE = !DEBUG_MODE_STATE;
    render();
};
