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
	sf::Vector2f mousePosView;
	
	//Game Clases
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;
	//Resources
	sf::Font font;
	//Text
	 sf::Text text;
	//Game Logic
	bool endGame;
	int health;
	float points; 
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemy;
	bool mouseHead;
public:
	//Constructor y Destructor
	gamePlay();
	virtual ~gamePlay();
	//Sets & Gets
	void setPoints(float p);
	float  getPoints();
	//Funciones
	void update();
	void render();
	//Accesorios
	const bool runnig()const;
	const bool getEndGame()const;

protected:
	//Funciones Aux
	void spawnEnemy();
	//init
	void initVariables();
	void initWindows();
	void initFonts();
	void initText();
	void initEnemy();
	//Update
	void updateEvent();
	void updateMousePosition();
	void updateEnemy();
	void updateText();
	//Draw
	void drawEnemies(sf::RenderTarget& target);
	void drawText(sf::RenderTarget& target);

};

