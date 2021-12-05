//
// Created by Asif Islam on 12/4/21.
//

#ifndef P4_3504C_ASIF_BUTTON_H
#define P4_3504C_ASIF_BUTTON_H
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



#endif //P4_3504C_ASIF_BUTTON_H


