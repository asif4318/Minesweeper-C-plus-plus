#include "MineTile.h"
#include "Toolbox.h"
#include <iostream>
#include <SFML/Graphics.hpp>

MineTile::MineTile(sf::Vector2f position) : Tile(position)
{
    this->position = position;
    sprite.setPosition(getLocation().x * 32, getLocation().y * 32);

    //Load textures
    if (!this->hidden.loadFromFile("images/tile_hidden.png"))
    {
        std::cerr << std::endl;
    }
    if (!this->revealed.loadFromFile("images/tile_revealed.png"))
    {
        std::cerr << std::endl;
    }

    createExplodedTexture();
    createFlaggedTexture();

    setState(HIDDEN);
}

//Combines mine.png & revealed together
void MineTile::createExplodedTexture()
{
    sf::RenderTexture renderTexture;
    renderTexture.create(32, 32);

    sf::Texture mine;
    mine.loadFromFile("images/mine.png");

    sf::Sprite mineSprite;
    mineSprite.setTexture(mine);
    sf::Sprite revealedSprite;
    revealedSprite.setTexture(revealed);

    renderTexture.draw(revealedSprite);

    renderTexture.draw(mineSprite);

    renderTexture.display();
    this->explodedTexture.loadFromImage(renderTexture.getTexture().copyToImage());
}

void MineTile::draw()
{
    Toolbox *tb = Toolbox::getInstance();
    sprite.setPosition(getLocation().x * 32, getLocation().y * 32);
    tb->window.draw(sprite);
}

void MineTile::onClickLeft()
{
    if (getState() == HIDDEN && getState() != FLAGGED)
    {
        setState(EXPLODED);
        Toolbox *tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
    }

    if (getState() == REVEALED) //Handle when debugged mine is clicked
    {
        setState(EXPLODED);
        Toolbox *tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
    }
}

void MineTile::onClickRight()
{
    switch (this->state)
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

Tile::State MineTile::getState()
{
    return this->state;
}

void MineTile::setState(State _state)
{
    switch (_state)
    {
    case FLAGGED:
    {
        sprite.setTexture(flaggedTexture);
        this->state = FLAGGED;
        break;
    }
    case HIDDEN:
    {
        sprite.setTexture(hidden);
        this->state = HIDDEN;
        break;
    }
    case EXPLODED:
    {
        sprite.setTexture(explodedTexture);
        Toolbox *tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
        this->state = EXPLODED;
        break;
    }
    case REVEALED:
    {
        sprite.setTexture(explodedTexture);
        this->state = REVEALED;
        break;
    }
    default:
        break;
    }
}

void MineTile::createFlaggedTexture()
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