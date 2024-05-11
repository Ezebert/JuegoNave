#include <SFML/Graphics.hpp>

int main()
{
    //INICIALIZACION
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUEGO EN CONSTRUCCION");
    sf::Sprite _personaje;
    sf::Texture _personajeTextura;
    _personajeTextura.loadFromFile("../img/nave.png");
    _personaje.setTexture(_personajeTextura);


    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    */



    //GAME LOOP
    while (window.isOpen())
    {
        //=GAME LOOP _ COMANDOS

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //=GAME LOOP _ UPDATE
        window.clear();

        //= GAME LOOP = DIBUJOS 
        window.draw(_personaje);

        //===GAME LOOP DISPPLAY FLIP
        window.display();
    }

    return 0;
}