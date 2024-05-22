#include "clsAsteroide.h"
#include <random>
#include <iostream>
clsAsteroide::clsAsteroide()
{
	_vel = 5;
	_texture.loadFromFile("../img/asteroide.png");
	_sprite.setTexture(_texture);
	
}
clsAsteroide::clsAsteroide(int x, int y )
{
	_vel = 5;
	_texture.loadFromFile("../img/asteroide.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(x, y);
}
void clsAsteroide::upDate()
{
}
void clsAsteroide::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(_sprite, states);
}

void clsAsteroide::createRandom(sf::RenderWindow window)
{
	std::cout << window.getSize().x;
}
/*
void clsAsteroide::createRandom()
{
	_sprite.setPosition(std::rand()%700 +_sprite.getGlobalBounds().width,100);
}
*/

