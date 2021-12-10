#include "MineTile.h"
#include "Toolbox.h"
#include <iostream>
#include <SFML/Graphics.hpp>

MineTile::MineTile(sf::Vector2f position) : Tile(position)
{
    isMine = true;
    this->position = position;
    this->sprite = new sf::Sprite();
    sprite->setPosition(this->position);

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

    sprite->setTexture(this->hidden);

    setState(HIDDEN);
}

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
    tb->window.draw(*this->sprite);
}

void MineTile::onClickLeft()
{
    if (getState() == HIDDEN && getState() != FLAGGED)
    {
        setState(EXPLODED);
        Toolbox *tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
    }
}

void MineTile::setState(State _state)
{
    switch (_state)
    {
    case FLAGGED:
    {
        sprite->setTexture(flaggedTexture);
        break;
    }
    case HIDDEN:
    {
        sprite->setTexture(hidden);
        break;
    }
    case EXPLODED:
    {
        sprite->setTexture(explodedTexture);
        Toolbox *tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
        break;
    }
    case REVEALED:
    {
        sprite->setTexture(explodedTexture);
        break;
    }
    default:
        break;
    }

    this->state = _state;
}

void MineTile::onClickRight()
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