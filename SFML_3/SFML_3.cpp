#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <cstdio>



#include "clsPlayer.h"
#include "clsAsteroide.h"
int main()
{
    //INICIALIZACION
    std::srand((unsigned)std::time(0)   );
    //INICIALIZACION -> VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUEGO EN CONSTRUCCION"); 
    window.setFramerateLimit(60);

    //INICIALIZACION -> NAVE

    clsPlayer _nave(window.getSize().x / 2, window.getSize().y * 0.8); //X = Mitad de Pantalla ; Y = 1/3 de Pantalla aprox
    //clsAsteroide _asteroide;
    clsAsteroide _asteroide;

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
        _asteroide.upDate();

        window.clear();

        //=== GAME LOOP = DIBUJOS ===
        
        //window.draw(_personaje);
        window.draw(_nave);
        window.draw(_asteroide);

        //=== GAME LOOP DISPPLAY FLIP ===
        window.display();
    }

    return 0;
}