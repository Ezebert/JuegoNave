#pragma once
#include <SFML/Graphics.hpp>
class clsPlayer
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
public:
	clsPlayer();
	void upDate();
	void draw(sf::RenderWindow&);

};

