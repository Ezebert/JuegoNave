#include <SFML/Graphics.hpp>
#include "clsPlayer.h"
#include <Windows.h>

int main()
{
    //INICIALIZACION
    //INICIALIZACION -> VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUEGO EN CONSTRUCCION");
    window.setFramerateLimit(60);

    //INICIALIZACION -> NAVE

    clsPlayer _nave;


    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    */



    //GAME LOOP
    while (window.isOpen())
    {
        // === Perifericos de entradas ===
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        //==== GAME LOOP _ UPDATE ===

        _nave.upDate();
        window.clear();

        //=== GAME LOOP = DIBUJOS ===
        
        //window.draw(_personaje);
        _nave.draw(window);

        //=== GAME LOOP DISPPLAY FLIP ===
        window.display();
    }

    return 0;
}