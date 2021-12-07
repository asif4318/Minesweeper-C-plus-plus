#include "Tile.h"
#include "Toolbox.h"
#include <iostream>

void Tile::onClickLeft()
{
    if (state == HIDDEN)
    {
        state = REVEALED;
        sprite.setTexture(revealed);
        sprite.setColor(sf::Color::Red);
    }
}

void Tile::onClickRight()
{
    if (state == FLAGGED)
        state = HIDDEN;
    if (state == HIDDEN)
        state = FLAGGED;
};

Tile::Tile(sf::Vector2f position)
{
    this->position = position;
    state = HIDDEN;
    if (!hidden.loadFromFile("images/tile_hidden.png"))
    {
        std::cerr << std::endl;
    }
    if (!revealed.loadFromFile("images/tile_revealed.png"))
    {
        std::cerr << std::endl;
    }
    //Set Texture to hidden by default
    sprite.setTexture(hidden);
    sprite.setPosition(this->position);
}

sf::Vector2f Tile::getLocation()
{
    return position;
}

void Tile::draw()
{
    Toolbox *tb = Toolbox::getInstance();
    tb->window.draw(sprite);
}

void Tile::setState(State _state)
{
    this->state = _state;
}