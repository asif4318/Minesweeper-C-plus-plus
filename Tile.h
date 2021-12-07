#pragma once
#include <SFML/Graphics.hpp>

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
    sf::Sprite sprite;

private:
    State state;
    sf::Vector2f position;
    static inline sf::Texture hidden;
    static inline sf::Texture revealed;
    bool isMine;

public:
    Tile(sf::Vector2f position);

    sf::Vector2f getLocation();

    State getState();

    //std::array<Tile *> &getNeighbors();

    void setState(State _state);
    //void setNeighbors(std::array<Tile *> _neighbors);
    void onClickLeft();
    void onClickRight();
    void draw();
    bool getIsMine();
    bool setIsMine();
    //void revealNeighbors();
};
