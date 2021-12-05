//
// Created by Asif Islam on 12/4/21.
//

#ifndef P4_3504C_ASIF_TOOLBOX_H
#define P4_3504C_ASIF_TOOLBOX_H
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Button.h"


class Toolbox {
private:
    Toolbox();
    static Toolbox *instance;
public:
    sf::RenderWindow window;
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;
    Toolbox* getInstance();
};


#endif //P4_3504C_ASIF_TOOLBOX_H
