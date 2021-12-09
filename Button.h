//
// Created by Asif Islam on 12/4/21.
//

#pragma once 

#include "Button.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
private:
    sf::Vector2f position;
    sf::Sprite *sprite;
    std::function<void(void)> callback;
public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick);
    sf::Vector2f getPosition();
    sf::Sprite *getSprite();
    void setSprite(sf::Sprite* _sprite);
    void onClick();
};


