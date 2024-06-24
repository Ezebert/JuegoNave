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
	//Mouse Posicion
	sf::Vector2i mousePosWindows;
	//Game Clases
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	//Game Logic
	int points; 
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemy;
public:
	//Constructor y Destructor
	gamePlay();
	virtual ~gamePlay();
	//Funciones
	void update();
	void render();
	const bool runnig()const;
	void spawnEnemy();

protected:
	//init
	void initVariables();
	void initWindows();
	void initEnemy();
	//Update
	void updateEvent();
	void updateMousePosition();
	void updateEnemy();
	//Draw
	void drawEnemies();
	

};

