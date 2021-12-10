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
    sf::Sprite sprite;
    State state;
    int numOfMines = 0;
    void setRevealedSprite();
    sf::Vector2f position;
    static inline sf::Texture hidden;
    sf::Texture revealed;
    static inline sf::Texture flaggedTexture;
    std::array<Tile *, 8> neighbor;
    void createFlaggedTexture();

public:
    bool isMine;
    Tile(sf::Vector2f position);

    sf::Vector2f getLocation();

    State getState();

    std::array<Tile *, 8> &getNeighbors();
    void setNeighbors(std::array<Tile *, 8> _neighbors);

    virtual void setState(State _state);
    virtual void onClickLeft();
    virtual void onClickRight();
    virtual void draw();
    bool getIsMine();

protected:
    void revealNeighbors();
};
