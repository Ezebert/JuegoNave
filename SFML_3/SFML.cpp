#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
//ramddom
#include <ctime>
#include <stdlib.h>
//Archivos .h
#include "gamePlay.h"

int main()
{
    /*
    //Windows
    sf::RenderWindow window(sf::VideoMode(800, 600), "GAME -  MAIN");
    */
    gamePlay game; 
    //GAME LOOP
    while (game.runnig())
    {
        game.update();
        game.render();
    }

    return 0;
}