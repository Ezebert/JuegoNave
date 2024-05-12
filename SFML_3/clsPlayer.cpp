#include "clsPlayer.h"

clsPlayer::clsPlayer()
{
	_texture.loadFromFile("../img/nave.png");
	_sprite.setTexture(_texture);
	_vel = 10;
}

clsPlayer::clsPlayer(int x, int y)
{
	_texture.loadFromFile("../img/nave.png");
	_sprite.setTexture(_texture);
	_vel = 10;
	_sprite.setPosition(x, y);
}

void clsPlayer::upDate()
{
	//Teclado
	isPress();
	//Controlar los extremos
	controlExtreme();

}
//DIBUJA el SPRITE
void clsPlayer::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(_sprite,states);
}

void clsPlayer::isPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_sprite.move(0, -_vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_sprite.move(-_vel, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_sprite.move(0, _vel);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_sprite.move(_vel, 0);
	}
}

void clsPlayer::controlExtreme()
{
	//EJE X
	if (_sprite.getPosition().x < 0) {
		_sprite.setPosition(0, _sprite.getPosition().y);
	}
	if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800) {
		_sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
	}
	//EJE Y
	if (_sprite.getPosition().y < 400) {
		_sprite.setPosition(_sprite.getPosition().x, 400);
	}
	if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
		_sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
	}
}


