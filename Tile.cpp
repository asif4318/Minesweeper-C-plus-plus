#include "Tile.h" //Also includes definition for MineTile.h
#include "Toolbox.h"
#include <iostream>

void Tile::onClickLeft()
{
    if (state == HIDDEN && state != FLAGGED)
    {
        setState(REVEALED);
        revealNeighbors();
    }
}

void Tile::onClickRight()
{
    switch (state)
    {
    case FLAGGED:
    {
        setState(HIDDEN);
        std::cout << "HIDDEN!\n";

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

    //Create flagged + hidden Tile texture with RenderTexture
    createFlaggedTexture();
    //Set Texture to hidden by default
    sprite.setTexture(hidden);
    sprite.setPosition(this->position);
}

void Tile::createFlaggedTexture()
{
    sf::Texture flag;
    if (!flag.loadFromFile("images/flag.png"))
    {
        std::cerr << std::endl;
    }
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

void Tile::setRevealedSprite()
{
    int mineCount = 0;
    //Count the number of neighboring mines
    for (int i = 0; i < 8; i++)
    {
        if (neighbors[i] != nullptr)
        {
            if (dynamic_cast<MineTile *>(neighbors[i]))
                mineCount++;
        }
    }

    //std::cout << "Tile Mine count is: " << mineCount << std::endl;
    if (mineCount != 0)
    {
        sf::RenderTexture renderTexture;
        renderTexture.create(32, 32);
        sf::Texture numberTexture;
        if (!numberTexture.loadFromFile("images/number_" + std::to_string(mineCount) + ".png"))
            ;
        {
            std::cerr << std::endl;
        }

        sf::Sprite revealedTile;
        sf::Sprite numberedSprite;

        revealedTile.setTexture(revealed);
        numberedSprite.setTexture(numberTexture);

        renderTexture.draw(revealedTile);
        renderTexture.draw(numberedSprite);
        renderTexture.display();

        revealed.loadFromImage(renderTexture.getTexture().copyToImage());
    }
}

std::array<Tile *, 8> &Tile::getNeighbors()
{
    return neighbors;
}

void Tile::setNeighbors(std::array<Tile *, 8> _neighbors)
{
    neighbors = _neighbors;
    setRevealedSprite();
}

void Tile::revealNeighbors()
{
    bool hasMine = false;
    for (int i = 0; i < 8; i++)
    {
        if (neighbors[i] != nullptr)
        {
            if (dynamic_cast<MineTile *>(neighbors[i]) || neighbors[i]->getState() == FLAGGED)
            {
                hasMine = true;
            }
        }
    };

    if (hasMine == false)
    {
        for (int i = 0; i < 8; i++)
        {
            if (neighbors[i] != nullptr)
            {
                //Don't go over tiles that are already revealed;
                if (neighbors[i]->getState() != REVEALED)
                {
                    //std::cout << "Location of revealed tile is: " << position.x << ", " << position.y << std::endl;

                    neighbors[i]->setState(Tile::REVEALED);
                    neighbors[i]->revealNeighbors();
                }
            }
        }
    }
}