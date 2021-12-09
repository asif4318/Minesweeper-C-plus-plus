#include "MineTile.h"
#include "Toolbox.h"
#include <iostream>
#include <SFML/Graphics.hpp>

MineTile::MineTile(sf::Vector2f position) : Tile(position)
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

    explodedTexture.loadFromImage(renderTexture.getTexture().copyToImage());

    isMine = true;
}

void MineTile::onClickLeft()
{
    if (state == HIDDEN && state != FLAGGED)
    {
        setState(REVEALED);
        Toolbox* tb = Toolbox::getInstance();
        tb->window.close();
    }
}

void MineTile::setState(State _state)
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
        sprite.setTexture(explodedTexture);
        Toolbox* tb = Toolbox::getInstance();
        tb->gameState->setPlayStatus(GameState::LOSS);
    }
    default:
        break;
    }

    this->state = _state;
}