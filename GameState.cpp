//
// Created by Asif Islam on 12/4/21.
//

#include "GameState.h"
#include "MineTile.h"
#include <iostream>
#include <vector>
#include <chrono>ç
#include <random>
#include <fstream>

GameState::GameState(sf::Vector2f _dimensions, int _numberOfMines)
{
    //Create vector of 1's and 0's and then shuffle for randomizatoin
    std::vector<int> randomBoard = std::vector<int>();
    for (int i = 0; i < _numberOfMines; i++)
    {
        randomBoard.push_back(1);
    }
    for (int i = 0; i < (_dimensions.x * _dimensions.y - _numberOfMines); i++)
    {
        randomBoard.push_back(0);
    }

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(randomBoard.begin(), randomBoard.end(), std::default_random_engine(seed));

    //Use 1's and 0's to construct Mines and Normal Tiles in those locations
    for (int i = 0; i < _dimensions.y; i++)
    {
        std::vector<Tile *> tiles;
        for (int j = 0; j < _dimensions.x; j++)
        {
            if (randomBoard[j * i + j] == 1)
            {
                tiles.push_back(new MineTile(sf::Vector2f(j, i)));
            }
            else if (randomBoard[j * i + j] == 0)
            {
                tiles.push_back(new Tile(sf::Vector2f(j, i)));
            }
        }
        gameBoard.push_back(tiles);
    }
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
            if (tiles.size() > 0)
                gameBoard.push_back(tiles);
        }
    }
    else
    {
        std::cerr << std::endl;
    }
}

Tile *GameState::getTile(int x, int y)
{
    if (y > gameBoard.size())
        return nullptr;
    if (x > gameBoard[0].size())
        return nullptr;
    return gameBoard[y][x];
}

int GameState::getFlagCount()
{
    int flagCount = 0;

    for (int i = 0; i < gameBoard.size(); i++)
    {
        for (int j = 0; j < gameBoard[0].size(); j++)
        {
            if (gameBoard[i][j]->getState() == 2)
                flagCount++;
        }
    }

    return flagCount;
}

GameState::PlayStatus GameState::getPlayStatus()
{
    return status;
}

void GameState::setPlayStatus(PlayStatus _status)
{
    this->status = _status;
}