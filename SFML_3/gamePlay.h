#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class gamePlay
{
private:
	//Variables
	//Windows
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

public:
	//Constructor y Destructor
	gamePlay();
	virtual ~gamePlay();
	//Funciones
	void update();
	void render();
	const bool runnig()const;

protected:
	void initialVariables();
	void initWindows();
	void updateEvent();
	

};

