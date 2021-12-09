#include "Toolbox.h"

Toolbox::Toolbox()
{
    window.create(sf::VideoMode(800, 600), "P4 - Minesweeper, Asif Islam");
    instance = nullptr;
    window.clear(sf::Color::White);

    debugTexture.loadFromFile("images/debug.png");
    sf::Sprite *debugButtonSprite = new sf::Sprite();

    void (*foo)();

    debugButton = new Button(sf::Vector2f(0, 32 * 16), foo);
    debugButton->setSprite(new sf::Sprite());
    debugButton->getSprite()->setTexture(debugTexture);
    debugButton->getSprite()->setPosition(0,32*16);
}

Toolbox *Toolbox::getInstance()
{
    if (!instance)
    {
        instance = new Toolbox();
    }
    return instance;
}