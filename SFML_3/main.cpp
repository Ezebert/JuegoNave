#include <SFML/Graphics.hpp>

int main()
{
    //INICIALIZACION DE LA VENTANA

    sf::RenderWindow window(sf::VideoMode(200, 200), "Nombre del juego");

    //SPRITE
    sf::Sprite personaje;
    sf::Texture personajeTextura;



        //GAME LOOP -> COMANDOS
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            //LIBERACION DEL JUEGO
            window.clear();
            window.draw(shape);
            window.display();
        }

    return 0;
}