#pragma once
#include <SFML/Graphics.hpp>
#include "clsPlayer.h"
class GamePlay : public sf::Drawable
{
public:
	GamePlay(sf::RenderWindow& _window);
	bool isRunning();
	void run();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //Dibujar
private:
	clsPlayer _player;
	

};

