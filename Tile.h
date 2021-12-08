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

private:
    State state;
    sf::Vector2f position;
    sf::Sprite sprite;

    static inline sf::Texture hidden;
    static inline sf::Texture revealed;
    static inline sf::Texture flaggedTexture;
    std::array<Tile*, 8> neighobrs;
    bool isMine;

public:
    Tile(sf::Vector2f position);

    sf::Vector2f getLocation();

    State getState();

    std::array<Tile *, 8> &getNeighbors();
    void setNeighbors(std::array<Tile *, 8> _neighbors);

    void setState(State _state);
    void onClickLeft();
    void onClickRight();
    void draw();
    bool getIsMine();
    bool setIsMine();
    //void revealNeighbors();
};
