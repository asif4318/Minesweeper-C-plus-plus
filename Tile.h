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

protected:
    State state;
    sf::Vector2f position;
    sf::Sprite sprite;

    static inline sf::Texture hidden;
    static inline sf::Texture revealed;
    static inline sf::Texture flaggedTexture;
    std::array<Tile*, 8> neighobrs;

public:
    Tile(sf::Vector2f position);

    sf::Vector2f getLocation();

    State getState();

    std::array<Tile *, 8> &getNeighbors();
    void setNeighbors(std::array<Tile *, 8> _neighbors);

    virtual void setState(State _state);
    virtual void onClickLeft();
    void onClickRight();
    void draw();
    //void revealNeighbors();
};
