#pragma once
#include "Tile.h"

class MineTile : public Tile
{
private:
    static inline sf::Texture explodedTexture;

public:
    MineTile(sf::Vector2f position);
    void onClickLeft();
    void setState(State _state);
};