//
// Created by Asif Islam on 12/4/21.
//

#include "GameState.h"
#include "MineTile.h"
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
                    tiles.push_back(new MineTile(sf::Vector2f(i, gameBoard.size())));
                }
                else if (line[i] == '0')
                {
                    tiles.push_back(new Tile(sf::Vector2f(i, gameBoard.size())));
                }
            }
            if (tiles.size() > 0) gameBoard.push_back(tiles);
        }
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

int GameState::getFlagCount() {
    int flagCount = 0;

    for (int i = 0; i < gameBoard.size(); i++) {
        for (int j = 0; j < gameBoard[0].size(); j++) {
            if (gameBoard[i][j]->getState() == 2) flagCount++;
        }
    }

    return flagCount;
}

void GameState::setPlayStatus(PlayStatus _status) {
    this->status = _status;
}