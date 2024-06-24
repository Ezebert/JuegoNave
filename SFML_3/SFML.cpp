#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
//ramddom
#include <ctime>
#include <stdlib.h>
//Archivos .h
#include "GamePlay.h"


int main()
{
    //Windows
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUEGO EN CONSTRUCCION" ); 
    window.setFramerateLimit(60);
    sf::Event event;

    //GAME LOOP
    while (window.isOpen())
    {
        // === Perifericos de entradas ===
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            default:
                break;
            }
        }
        window.clear();
        window.display();           
    }

    return 0;
}