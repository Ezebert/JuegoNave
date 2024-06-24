#include "gamePlay.h"
#include <Windows.h>
#include <iostream>

gamePlay::gamePlay()
{
    this->initialVariables();
    this->initWindows();
    this->initEnemy();
}

gamePlay::~gamePlay()
{
	delete this->window;
}

void gamePlay::update()
{
  this->updateEvent(); //PoolEvents

  this->updateMousePosition();
  this->upodateEnemy();


}

void gamePlay::render(){
    // Clear - Render(draw) - Display 
    this->window->clear();
    //Draw obj
    this->window->draw(this->enemy);


    this->window->display();
}
//======    ACCESSORS    ======i
const bool gamePlay::runnig() const { 	
    return this->window->isOpen();
}
void gamePlay::spawnEnemy()
{

}
//======    INIT    ======
void gamePlay::initVariables(){
	this->window = nullptr;
    //Game Logic
    this->points=0;
    this->enemySpawnTimer = 0.f;
    this->enemySpawnTimerMax = 1000.f;;
    this->maxEnemy = 5;

}
void gamePlay::initWindows(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "GAME - RUN", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}
void gamePlay::initEnemy()
{
    this->enemy.setPosition(20.f,10.f);//(x , y)
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f)); //reduce tama�o
    this->enemy.setFillColor(sf::Color::Red
    );//cuerpo
    this->enemy.setOutlineColor(sf::Color::Green);//contorno
    this->enemy.setOutlineThickness(10.f); // Grosor del contorno
}
//======    UPDATE    ======
void gamePlay::updateEvent()
{
    
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed ) {
            std::cout << "Salir";
            this->window->close();
        }

    }
    

    /*
    while (this->window->pollEvent(this->event));
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            std::cout << "salir";
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.scancode == sf::Keyboard::Up) {
                std::cout << "salir scan";
                this->window->close();

            }
            break;
        }
    }
    */
}

void gamePlay::updateMousePosition()
{
    //Update Mouse Position relativa  de windows vector2i
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << " \n";
    this->mousePosWindows = sf::Mouse::getPosition(*this->window);
}
