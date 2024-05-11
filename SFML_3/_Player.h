#pragma once
#include <SFML/Graphics.hpp>
class _Player
{
private:
	sf::Sprite _personaje;
	sf::Texture _personajeTextura;
	float velocidad;
public:
	_Player();
	void upDate();

};

