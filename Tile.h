#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Tile
{
public:
    enum State
    {
        REVEALED,
        HIDDEN,
        FLAGGED,
        EXPLODED
    };

private:
    sf::Sprite sprite; //Tile sprite
    State state;
    void setRevealedSprite(); //Create a sprite based on number of surrounding mines
    sf::Vector2f position;
    static inline sf::Texture hidden;
    sf::Texture revealed;
    static inline sf::Texture flaggedTexture;
    std::array<Tile *, 8> neighbors;
    void createFlaggedTexture();

public:
    Tile(sf::Vector2f position);

    sf::Vector2f getLocation();

    virtual State getState();

    std::array<Tile *, 8> &getNeighbors();
    void setNeighbors(std::array<Tile *, 8> _neighbors);

    virtual void setState(State _state);
    virtual void onClickLeft();
    virtual void onClickRight();
    virtual void draw();

protected:
    void revealNeighbors();
};

#include "MineTile.h"