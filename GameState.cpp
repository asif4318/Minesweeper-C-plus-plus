//
// Created by Asif Islam on 12/4/21.
//

#include "GameState.h"
#include "MineTile.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

GameState::GameState(sf::Vector2f _dimensions, int _numberOfMines)
{
    //Set Mine count
    mineCount = _numberOfMines;
    //Set state to Playing
    status = PLAYING;
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

    createTileNeighbors();
}

GameState::GameState(const char *filepath)
{
    status = PLAYING;

    mineCount = 0;
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
                    mineCount++;
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

    createTileNeighbors();
}

Tile *GameState::getTile(int x, int y)
{
    if (y >= gameBoard.size() || y < 0)
        return nullptr;
    if (x >= gameBoard[0].size() || x < 0)
        return nullptr;
    return gameBoard[y][x];
}

int GameState::getMineCount() { return mineCount; }

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

void GameState::createTileNeighbors()
{
    for (int i = 0; i < gameBoard.size(); i++)
    {
        for (int j = 0; j < gameBoard[i].size(); j++)
        {
            std::array<Tile *, 8> tileNeighbor;
            for (int i = 0; i < 8; i++)
                tileNeighbor[i] = nullptr;

            //Set the left neighbor
            if (j != 0)
                tileNeighbor[3] = gameBoard[i][j - 1];
            //Set the right neighbor
            if (j != gameBoard[i].size() - 1)
                tileNeighbor[4] = gameBoard[i][j + 1];
            //Set the top neighbor
            if (i != 0)
                tileNeighbor[1] = gameBoard[i - 1][j];
            //Set the bottom neighbor
            if (i != gameBoard.size() - 1)
                tileNeighbor[6] = gameBoard[i + 1][j];

            //Set top left
            if (j != 0 && i != 0)
            {
                tileNeighbor[0] = gameBoard[i - 1][j - 1];
            }
            //Set top right
            if (j != gameBoard[i].size() - 1 && i != 0)
            {
                tileNeighbor[2] = gameBoard[i - 1][j + 1];
            }
            //Set Bottom Left
            if (j != 0 && i != gameBoard.size() - 1)
            {
                tileNeighbor[5] = gameBoard[i + 1][j - 1];
            }
            //Set Bottom Right
            if (j != gameBoard[i].size() - 1 && i != gameBoard.size() - 1)
            {
                tileNeighbor[7] = gameBoard[i + 1][j + 1];
            }

            gameBoard[i][j]->setNeighbors(tileNeighbor);
        }
    }
}

GameState::~GameState()
{
    for (int i = 0; i < gameBoard.size(); i++)
    {
        for (auto tile : gameBoard[i])
        {
            delete tile;
        }
        gameBoard[i].clear();
    }
    gameBoard.clear();
}