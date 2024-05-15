#include "clsAsteroide.h"
#include <random>
clsAsteroide::clsAsteroide()
{
	_vel = 5;
	_texture.loadFromFile("../img/asteroide.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(400,200);
	
}
clsAsteroide::clsAsteroide(int, int)
{
	_vel = 5;
	_texture.loadFromFile("../img/asteroide.png");
	_sprite.setTexture(_texture);
}
void clsAsteroide::upDate()
{

}
void clsAsteroide::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(_sprite, states);
}

void clsAsteroide::createRandom(int x, int y)
{
	_sprite.setPosition(x, y);
}

