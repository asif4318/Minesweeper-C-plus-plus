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
#include <string>
#include <vector>

bool DEBUG_MODE_STATE = false;

void render();

void restart();

void loadTest1Board();

void loadTest2Board();

void loadTest3Board();

void toggleDebugMode();

sf::Vector2i getBoardDimensions();

bool getDebugMode();

int gameLoop();

int launch()
{
    Toolbox *tb = Toolbox::getInstance();
    tb->gameState = new GameState();
    gameLoop();
    return 0;
};

int gameLoop()
{
    Toolbox *tb = Toolbox::getInstance();

    //Load Game Button textures
    sf::Texture loserFace, happyFace, winnerFace;
    sf::Texture debugTexture;
    sf::Texture test1Texture, test2Texture, test3Texture;

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
    if (!test3Texture.loadFromFile("images/test_3.png"))
    {
        std::cerr << std::endl;
    }

    //Create function pointers to pass to buttons as callbacks
    void (*newGameFunc)() = &restart;
    void (*testGame1Func)() = &loadTest1Board;
    void (*testGame2Func)() = &loadTest2Board;
    void (*testGame3Func)() = &loadTest3Board;

    //Allocate new Buttons, positions set by the side length of a tile 32;
    //Set newGameButton to center
    tb->newGameButton = new Button(sf::Vector2f(tb->window.getSize().x / 2, 32 * 16), newGameFunc);
    tb->newGameButton->setSprite(new sf::Sprite());
    tb->newGameButton->getSprite()->setTexture(happyFace);
    tb->newGameButton->getSprite()->move(-(tb->newGameButton->getSprite()->getGlobalBounds().width / 2), 0);

    tb->testButton1 = new Button(sf::Vector2f(32 * 18, 32 * 16), testGame1Func);
    tb->testButton1->setSprite(new sf::Sprite());
    tb->testButton1->getSprite()->setTexture(test1Texture);

    //Set Debug to the left of the first button
    tb->debugButton = new Button(sf::Vector2f(32 * 18, 32 * 16), &toggleDebugMode);
    tb->debugButton->setSprite(new sf::Sprite());
    tb->debugButton->getSprite()->move(sf::Vector2f(-1 * (tb->testButton1->getSprite()->getGlobalBounds().width), 0));
    tb->debugButton->getSprite()->setTexture(debugTexture);

    //Set Test 2 to the immediate right of the first button
    tb->testButton2 = new Button(sf::Vector2f(32 * 18, 32 * 16), testGame2Func);
    tb->testButton2->setSprite(new sf::Sprite());
    tb->testButton2->getSprite()->move(sf::Vector2f(tb->testButton1->getSprite()->getGlobalBounds().width, 0));
    tb->testButton2->getSprite()->setTexture(test2Texture);

    //Set Test 3 to the immediate right of the second button
    tb->testButton3 = new Button(sf::Vector2f(32 * 18, 32 * 16), testGame3Func);
    tb->testButton3->setSprite(new sf::Sprite());
    tb->testButton3->getSprite()->move(sf::Vector2f(tb->testButton1->getSprite()->getGlobalBounds().width * 2, 0));
    tb->testButton3->getSprite()->setTexture(test3Texture);

    //Set Game Status
    tb->gameState->setPlayStatus(GameState::PLAYING);

    //Display all elements
    render();

    //Main event loop
    while (tb->window.isOpen())
    {
        sf::Event event;
        while (tb->window.pollEvent(event)) //Event Listener
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
                    Tile *tempTile = tb->gameState->getTile(mouseTileX, mouseTileY);
                    if (!tempTile) //Handle if tile does not exist
                    {
                        //Check if the mouse clicked one of the buttons
                        if (tb->newGameButton->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            /*If new Game Button is pressed, change button image back to happy face and perform
                                the callback*/
                            tb->newGameButton->getSprite()->setTexture(happyFace);
                            tb->newGameButton->onClick();
                        }

                        if (tb->testButton1->getSprite()->getGlobalBounds().contains(mousePosConverted))
                        {
                            tb->testButton1->onClick();
                            tb->newGameButton->getSprite()->setTexture(happyFace);
                        }
                        else if (tb->testButton2->getSprite()->getGlobalBounds().contains(
                                     mousePosConverted))
                        {
                            tb->testButton2->onClick();
                            tb->newGameButton->getSprite()->setTexture(happyFace);
                        }
                        else if (tb->debugButton->getSprite()->getGlobalBounds().contains(
                                     mousePosConverted))
                        {
                            tb->debugButton->onClick();
                        }
                    }
                    //Handle if a tile was clicked (tempTile is NOT NULL)
                    else if (tb->gameState->getPlayStatus() == GameState::PLAYING)
                    {
                        //Perform the left click;
                        tempTile->onClickLeft();

                        bool isWon = false;
                        int numMines = tb->gameState->getMineCount();
                        int tilesNotRevealed = 0;

                        for (int j = 0; j < getBoardDimensions().y; j++)
                        {
                            for (int i = 0; i < getBoardDimensions().x; i++)
                            {
                                Tile *currentTile = tb->gameState->getTile(i, j);
                                if (currentTile->getState() != Tile::REVEALED &&
                                    currentTile->getState() != Tile::EXPLODED)
                                    tilesNotRevealed++;
                            }
                        }

                        //If tiles not revealed equals number of mines -> win condition
                        if (tilesNotRevealed == numMines && tb->gameState->getPlayStatus() != GameState::LOSS)
                        {
                            tb->newGameButton->getSprite()->setTexture(winnerFace);
                            tb->gameState->setPlayStatus(GameState::WIN);
                        };

                        //If a loss is registered by onClickLeft() (mine clicked) set status to lost
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
                    Tile *tempTile = tb->gameState->getTile(mouseTileX, mouseTileY);
                    if (!tempTile)
                    {
                        std::cout << "Tile out of bounds" << std::endl;
                    }
                    else
                    {
                        //Perform the tiles right click action
                        tempTile->onClickRight();
                        render();
                    }
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

//Draw ALL UI Elements based on GameState
void render()
{
    Toolbox *tb = Toolbox::getInstance();
    tb->window.clear(sf::Color::White);

    //Load necessary textures
    sf::Texture digitsTexture;
    digitsTexture.loadFromFile("images/digits.png");

    //Following sprites & positions handle mine counter in bottom left corner of window
    sf::Vector2f hundredsSpritePosition = sf::Vector2f(0, getBoardDimensions().y * 32);
    sf::Vector2f tensSpritePosition = sf::Vector2f(21, getBoardDimensions().y * 32);
    sf::Vector2f onesSpritePosition = sf::Vector2f(42, getBoardDimensions().y * 32);

    sf::Sprite digit0, digit1, digit2, digit3, digit4, digit5,
        digit6, digit7, digit8, digit9, digitDash;

    //setTextureRect allows for rectangular subsection of texture to be used
    //Each digit has a width of 21, and a height of 32
    //To get each successive digit just multiply x * 21;
    digit0.setTexture(digitsTexture);
    digit0.setTextureRect(sf::IntRect(0, 0, 21, 32));
    digit1.setTexture(digitsTexture);
    digit1.setTextureRect(sf::IntRect(21 * 1, 0, 21, 32));
    digit2.setTexture(digitsTexture);
    digit2.setTextureRect(sf::IntRect(21 * 2, 0, 21, 32));
    digit3.setTexture(digitsTexture);
    digit3.setTextureRect(sf::IntRect(21 * 3, 0, 21, 32));
    digit4.setTexture(digitsTexture);
    digit4.setTextureRect(sf::IntRect(21 * 4, 0, 21, 32));
    digit5.setTexture(digitsTexture);
    digit5.setTextureRect(sf::IntRect(21 * 5, 0, 21, 32));
    digit6.setTexture(digitsTexture);
    digit6.setTextureRect(sf::IntRect(21 * 6, 0, 21, 32));
    digit7.setTexture(digitsTexture);
    digit7.setTextureRect(sf::IntRect(21 * 7, 0, 21, 32));
    digit8.setTexture(digitsTexture);
    digit8.setTextureRect(sf::IntRect(21 * 8, 0, 21, 32));
    digit9.setTexture(digitsTexture);
    digit9.setTextureRect(sf::IntRect(21 * 9, 0, 21, 32));
    digitDash.setTexture(digitsTexture);
    digitDash.setTextureRect(sf::IntRect(21 * 10, 0, 21, 32));

    //Create a vector of sprites;
    std::vector<sf::Sprite> digitVector = {digit0,
                                           digit1,
                                           digit2,
                                           digit3,
                                           digit4,
                                           digit5,
                                           digit6,
                                           digit7,
                                           digit8,
                                           digit9,
                                           digitDash};

    //Get assumed number of mines
    int mineCount = tb->gameState->getMineCount() - tb->gameState->getFlagCount();
    //Convert to string so each digit can be split individually
    std::string mineCountAsString = std::to_string(mineCount);

    //There's only 3 digits to work with based on the image provided in spec sheet of
    //Game Board
    if (mineCount > -100 && mineCount < 999)
    {
        //Handle mine count display based on # of digits
        switch (mineCountAsString.size())
        {
        case 3:
        {
            for (auto entry : digitVector)
            {
                //Organize all sprites into one position to be layered over
                entry.setPosition(hundredsSpritePosition);
            }

            //Subtract by 48 to converted digit as char to int;
            digitVector[(int)mineCountAsString[1] - 48].setPosition(tensSpritePosition);
            tb->window.draw(digitVector[(int)mineCountAsString[1] - 48]);
            digitVector[(int)mineCountAsString[2] - 48].setPosition(onesSpritePosition);
            tb->window.draw(digitVector[(int)mineCountAsString[2] - 48]);

            //Handle negative case
            if (mineCountAsString[0] == '-')
            {
                digitVector.back().setPosition(hundredsSpritePosition); //Vector back() is the minus digit
                tb->window.draw(digitVector.back());
            }
            else
            {
                digitVector[(int)mineCountAsString[0] - 48].setPosition(hundredsSpritePosition);
                tb->window.draw(digitVector[(int)mineCountAsString[0] - 48]);
            }

            break;
        }
        case 2:
        {
            for (auto entry : digitVector)
            {
                entry.setPosition(tensSpritePosition);
            }

            if (mineCountAsString[0] == '-')
            {
                digitVector.back().setPosition(tensSpritePosition);
                tb->window.draw(digitVector.back());
            }
            else
            {
                digitVector[(int)mineCountAsString[0] - 48].setPosition(tensSpritePosition);

                tb->window.draw(digitVector[(int)mineCountAsString[0] - 48]);
            }

            digitVector[(int)mineCountAsString[1] - 48].setPosition(onesSpritePosition);
            tb->window.draw(digitVector[(int)mineCountAsString[1] - 48]);

            break;
        }
        case 1:
        {
            for (auto entry : digitVector)
            {
                entry.setPosition(onesSpritePosition);
            }
            digitVector[(int)mineCountAsString[0] - 48].setPosition(onesSpritePosition);

            tb->window.draw(digitVector[(int)mineCountAsString[0] - 48]);
            break;
        }
        default:
            break;
        }
    }

    //Loop through tiles and draw them
    for (int j = 0; j < getBoardDimensions().y; j++)
    {
        for (int i = 0; i < getBoardDimensions().x; i++)
        {
            Tile *currentTile = tb->gameState->getTile(i, j);
            //Upcast to Mine Tile
            if (dynamic_cast<MineTile *>(currentTile))
            {
                MineTile *tileAsMinePtr = dynamic_cast<MineTile *>(currentTile);

                //Reveal all the mines if debug mode is on;
                if (getDebugMode() && tileAsMinePtr->getState() != Tile::State::EXPLODED)
                {
                    tileAsMinePtr->setState(Tile::REVEALED);
                }
                else if (!getDebugMode() && tileAsMinePtr->getState() != Tile::State::EXPLODED &&
                         tileAsMinePtr->getState() != Tile::State::FLAGGED)
                {
                    tileAsMinePtr->setState(Tile::HIDDEN);
                }
                tileAsMinePtr->draw();
            }
            else
            {
                currentTile->draw();
            }
        }
    }

    //Draw the button sprites;
    tb->window.draw(*tb->debugButton->getSprite());
    tb->window.draw(*tb->testButton1->getSprite());
    tb->window.draw(*tb->testButton2->getSprite());
    tb->window.draw(*tb->testButton3->getSprite());
    tb->window.draw(*tb->newGameButton->getSprite());

    //Finally display the updated window
    tb->window.display();
}

void restart()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    //Delete gameState to prevent mem leaks before creating new State
    tb->gameState = new GameState();
    render();
}

//Variation of restart but calls for board1
void loadTest1Board()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState("boards/testboard1.brd");
    render();
};

//Variation of restart but calls for board2
void loadTest2Board()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState("boards/testboard2.brd");
    render();
};

void loadTest3Board()
{
    Toolbox *tb = Toolbox::getInstance();
    delete tb->gameState;
    tb->gameState = new GameState("boards/testboard3.brd");
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

sf::Vector2i getBoardDimensions()
{
    Toolbox *tb = Toolbox::getInstance();

    int dimensionsX = 1;
    int dimensionsY = 1;
    Tile *sampleX = tb->gameState->getTile(0, 0);
    Tile *sampleY = tb->gameState->getTile(0, 0);

    while (sampleX->getNeighbors()[4] != nullptr)
    {
        dimensionsX++;
        sampleX = sampleX->getNeighbors()[4];
    }

    while (sampleY->getNeighbors()[6] != nullptr)
    {
        dimensionsY++;
        sampleY = sampleY->getNeighbors()[6];
    }

    return sf::Vector2i(dimensionsX, dimensionsY);
}

void drawMineCounter(std::vector<sf::Sprite *> _digits);

#endif //P4_3504C_ASIF_MINESWEEPER_H
