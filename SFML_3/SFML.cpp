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
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game
    gamePlay game; 

    //Game Loop
    while (game.runnig())
    {
        //Update
        game.update();
        //Render
        game.render();
    }

    return 0;
}