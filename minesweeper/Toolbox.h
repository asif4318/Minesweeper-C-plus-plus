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
    sf::Texture test1Texture, test2Texture, test3Texture;
    sf::Texture happyFace, loserFace, winnerFace;

public:
    sf::RenderWindow window;
    GameState *gameState;
    Button *debugButton, *newGameButton, *testButton1, *testButton2, *testButton3;
    static Toolbox *getInstance();
};
