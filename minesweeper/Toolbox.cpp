#include "Toolbox.h"

Toolbox::Toolbox()
{
    window.create(sf::VideoMode(800, 600), "P4 - Minesweeper, Asif Islam");
    window.setActive(true);
    instance = nullptr;
    window.clear(sf::Color::White);
}

Toolbox *Toolbox::getInstance()
{
    if (!instance)
    {
        instance = new Toolbox();
    }
    return instance;
}