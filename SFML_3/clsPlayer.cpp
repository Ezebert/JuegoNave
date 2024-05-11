#include "clsPlayer.h"

clsPlayer::clsPlayer()
{
	_texture.loadFromFile("../img/file.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(100, 100);
	_vel = 4;
}

void clsPlayer::upDate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_sprite.move(0, -_vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_sprite.move(-_vel, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_sprite.move(0,_vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_sprite.move(_vel, 0);
	}
	//Controlar los extremos
	//EJE X
	if (_sprite.getPosition().x < 0) {
		_sprite.setPosition(0,_sprite.getPosition().y);
	}
	if (_sprite.getPosition().x + _sprite.getGlobalBounds().width> 800) {
		_sprite.setPosition(800- _sprite.getGlobalBounds().width, _sprite.getPosition().y);
	}
	//EJE Y
	if (_sprite.getPosition().y < 0) {
		_sprite.setPosition(_sprite.getPosition().x,0);
	}
	if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
		_sprite.setPosition(_sprite.getPosition().x,600 - _sprite.getGlobalBounds().height);
	}
}

void clsPlayer::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

