#include "_Player.h"

_Player::_Player()
{
    _personajeTextura.loadFromFile("../img/file.png");
    _personaje.setTexture(_personajeTextura);
    velocidad = 5;
}

void _Player::upDate()
{
    //=== Comandos ¿Que se apreto? ===
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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

    //Controlamos el espacio
    if (_personaje.getPosition().x < 0) {
        _personaje.setPosition(0, _personaje.getPosition().y);
    }
    if (_personaje.getPosition().y < 0) {
        _personaje.setPosition(_personaje.getPosition().x, 0);
    }
    if (_personaje.getPosition().x + _personaje.getGlobalBounds().width > 800) {
        _personaje.setPosition(800 - _personaje.getGlobalBounds().width, _personaje.getPosition().y);
    }
    if (_personaje.getPosition().y + _personaje.getGlobalBounds().height > 600) {
        _personaje.setPosition(_personaje.getPosition().x, 600 - _personaje.getGlobalBounds().height);
    }
}
