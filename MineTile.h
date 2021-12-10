#pragma once
#include "Tile.h"

class MineTile : public Tile
{
private:
    State state;
    static inline sf::Texture explodedTexture;
    sf::Vector2f position;
    sf::Sprite sprite;
    static inline sf::Texture hidden;
    sf::Texture revealed;
    static inline sf::Texture flaggedTexture;
    std::array<Tile *, 8> neighbor;

public:
    MineTile(sf::Vector2f position);
    void onClickLeft();
    void setState(State _state);
};