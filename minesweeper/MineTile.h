#pragma once
#include "Tile.h"

class MineTile : public Tile
{
private:
    State state;
    sf::Vector2f position;
    sf::Sprite sprite;

private:
    static inline sf::Texture flag, hidden;
    sf::Texture revealed;

    static inline sf::Texture flaggedTexture;

    void createFlaggedTexture();
    static inline sf::Texture explodedTexture;
    void createExplodedTexture();

public:
    MineTile(sf::Vector2f position);
    void onClickLeft();
    void onClickRight();
    void setState(State _state);
    State getState();
    void draw();
};