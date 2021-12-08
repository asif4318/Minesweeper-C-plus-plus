//
// Created by Asif Islam on 12/4/21.
//

#include "GameState.h"
#include <iostream>
#include <fstream>

GameState::GameState(sf::Vector2f _dimensions, int _numberOfMines)
{
}

GameState::GameState(const char *filepath)
{
    std::string line;
    std::ifstream is(filepath);
    if (is.is_open())
    {
        while (std::getline(is, line))
        {
            std::vector<Tile *> tiles;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '1')
                {
                    //TODO: PUSH BACK A BOMB
                    tiles.push_back(new Tile(sf::Vector2f(i, gameBoard.size())));
                    //std::cout << "Bomb" << std::endl;
                }
                else if (line[i] == '0')
                {
                    tiles.push_back(new Tile(sf::Vector2f(i, gameBoard.size())));
                    //std::cout << "Normal" << std::endl;
                }
            }
            gameBoard.push_back(tiles);
        }
        is.close();
    }
    else
    {
        std::cerr << std::endl;
    }
}

Tile *GameState::getTile(int x, int y)
{
    if (y > gameBoard.size()) return nullptr;
    if (x > gameBoard[0].size()) return nullptr;
    return gameBoard[y][x];
}
