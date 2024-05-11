#include <SFML/Graphics.hpp>

int main()
{
    //INICIALIZACION
    //INICIALIZACION -> VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "JUEGO EN CONSTRUCCION");

    //INICIALIZACION -> NAVE
    sf::Sprite _personaje;
    sf::Texture _personajeTextura;
    _personajeTextura.loadFromFile("../img/file.png");
    _personaje.setTexture(_personajeTextura);


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
        //=== Comandos ¿Que se apreto? ===
        float velocidad = 0.04;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down  )) {
            _personaje.move(0, velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _personaje.move(0, -velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            _personaje.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            _personaje.move(-velocidad, 0);
        }
        //==== GAME LOOP _ UPDATE ===
        window.clear();

        //=== GAME LOOP = DIBUJOS ===
        window.draw(_personaje);

        //=== GAME LOOP DISPPLAY FLIP ===
        window.display();
    }

    return 0;
}