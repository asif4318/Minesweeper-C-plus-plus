//
// Created by Asif Islam on 12/4/21.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class GameState
{
private:
    std::vector< std::vector<Tile *> > gameBoard;
    
public:
    enum PlayStatus
    {
        WIN,
        LOSS,
        PLAYING
    };
    GameState(sf::Vector2f _dimensions = sf::Vector2f(25, 16), int _numberOfMines = 50);
    GameState(const char *filepath);
    int getFlagCount();
    int getMineCount();
    Tile *getTile(int x, int y);
    PlayStatus getPlayStatus();
    void setPlayStatus(PlayStatus _status);
};