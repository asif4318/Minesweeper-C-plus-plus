#include "Tile.h"
#include "Toolbox.h"
#include <iostream>

void Tile::onClickLeft()
{
    if (state == HIDDEN && state != FLAGGED)
    {
        setState(REVEALED);
    }
}

void Tile::onClickRight()
{
    switch (state)
    {
    case FLAGGED:
    {
        setState(HIDDEN);
        break;
    }
    case HIDDEN:
    {
        setState(FLAGGED);
        break;
    }
    default:
        break;
    }
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
    sf::Texture flag;
    if (!flag.loadFromFile("images/flag.png"))
    {
        std::cerr << std::endl;
    }

    //Create flagged + hidden Tile texture with RenderTexture
    sf::RenderTexture flaggedTile;
    flaggedTile.create(hidden.getSize().x, hidden.getSize().y);
    flaggedTile.clear(sf::Color::Black);

    sf::Sprite hiddenTileSprite;
    sf::Sprite flagSprite;
    hiddenTileSprite.setTexture(hidden);
    flagSprite.setTexture(flag);
    flaggedTile.draw(hiddenTileSprite);
    flaggedTile.draw(flagSprite);
    flaggedTile.display();
    flaggedTexture.loadFromImage(flaggedTile.getTexture().copyToImage());

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
    sprite.setPosition(getLocation().x * 32, getLocation().y * 32);
    tb->window.draw(sprite);
}

void Tile::setState(State _state)
{
    switch (_state)
    {
    case FLAGGED:
    {
        sprite.setTexture(flaggedTexture);
        break;
    }
    case HIDDEN:
    {
        sprite.setTexture(hidden);
        break;
    }
    case REVEALED:
    {
        sprite.setTexture(revealed);
    }
    default:
        break;
    }

    this->state = _state;
}

Tile::State Tile::getState()
{
    return state;
}

std::array<Tile *, 8> &Tile::getNeighbors() {
    return neighbor;
}

void Tile::setNeighbors(std::array<Tile *, 8> _neighbors) {
    neighbor = _neighbors;
}