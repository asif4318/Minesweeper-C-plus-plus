//
// Created by Asif Islam on 12/4/21.
//
#include "Button.h"

Button::Button(sf::Vector2f _position, std::function<void(void)> _onClick) {
    this->position = _position;
    this->callback = _onClick;
    this->sprite = nullptr;
}

void Button::onClick() {
    callback();
}

sf::Vector2f Button::getPosition() {
    return this->position;
}

sf::Sprite *Button::getSprite() {
    return this->sprite;
}

void Button::setSprite(sf::Sprite *_sprite) {
    sf::Sprite** spritePtr2Ptr = &_sprite;
    this->sprite = *spritePtr2Ptr;
    sprite->setPosition(position);
}