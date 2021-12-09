//
// Created by Asif Islam on 12/4/21.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Button.h"

class Toolbox
{
private:
    Toolbox();
    static inline Toolbox *instance;
    //Button Textures
    sf::Texture debugTexture;

public:
    sf::RenderWindow window;
    GameState *gameState;
    Button *debugButton;
    /*Button* newGameButton;
    Button* testButton1;
    Button* testButton2;*/
    static Toolbox *getInstance();
};
