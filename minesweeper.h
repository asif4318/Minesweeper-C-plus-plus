//
// Created by Asif Islam on 12/4/21.
//

#ifndef P4_3504C_ASIF_MINESWEEPER_H
#define P4_3504C_ASIF_MINESWEEPER_H
#include <SFML/Graphics.hpp>
#include "Toolbox.h"
#include "Tile.h"
#include "GameState.h"
#include <iostream>

#endif //P4_3504C_ASIF_MINESWEEPER_H

void render();
int gameLoop();

int launch()
{
    Toolbox *tb = Toolbox::getInstance();
    tb->gameState = new GameState("boards/testboard2.brd");
    render();
    gameLoop();
    return 0;
};

int gameLoop()
{
    Toolbox *tb = Toolbox::getInstance();

    while (tb->window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
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
                std::cout << "Mouse button pressed\n";
                unsigned int mouse_tile_x = (int) sf::Mouse::getPosition(tb->window).x / 32;
                unsigned int mouse_tile_y = (int) sf::Mouse::getPosition(tb->window).y / 32;
                
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:
                {
                    std::cout << mouse_tile_x << ", " << mouse_tile_y << std::endl;
                    Tile *tempTile = tb->gameState->getTile(mouse_tile_x,mouse_tile_y);
                    if (!tempTile) {
                        std::cout << "Tile out of bounds" << std::endl;
                    } else {
                        tempTile->onClickLeft();
                    }
                    render();
                    break;
                }
                case sf::Mouse::Right: {
                    std::cout << mouse_tile_x << ", " << mouse_tile_y << std::endl;
                    Tile *tempTile = tb->gameState->getTile(mouse_tile_x,mouse_tile_y);
                    if (!tempTile) {
                        std::cout << "Tile out of bounds" << std::endl;
                    } else {
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
    for (int j = 0; j < 16; j++)
    {
        for (int i = 0; i < 25; i++)
        {
            tb->gameState->getTile(i, j)->draw();
        }
    }

    tb->window.display();
}