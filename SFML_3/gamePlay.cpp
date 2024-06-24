#include "gamePlay.h"
#include <Windows.h>
#include <iostream>

gamePlay::gamePlay()
{
    this->initVariables();
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
  this->updateEnemy();


}

void gamePlay::render(){
    // Clear - Render(draw) - Display 
    this->window->clear();
    //Draw obj
    //this->window->draw(this->enemy);
    this->drawEnemies();
    this->window->display();
}
//======    ACCESSORS    ======i
const bool gamePlay::runnig() const { 	
    return this->window->isOpen();
}
void gamePlay::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
//        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
            );
    this->enemy.setFillColor(sf::Color::Yellow);
    //Add enemy 
    this->enemies.push_back(this->enemy);
}
//======    INIT    ======
void gamePlay::initVariables(){
	this->window = nullptr;
    //Game Logic
    this->points=0;
    this->enemySpawnTimerMax = 10.f;;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    
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
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f)); //reduce tamaño
    this->enemy.setFillColor(sf::Color::Red);//cuerpo
    this->enemy.setOutlineColor(sf::Color::Green);//contorno
    this->enemy.setOutlineThickness(10.f); // Grosor del contorno
}
//======    UPDATE    ======
void gamePlay::updateEvent()
{
    
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed ) {
            std::cout << "Points "<<this->points << "\n";
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
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindows);//posición convertida en coordenadas del mundo 2D
}

void gamePlay::updateEnemy()
{
    /*Actualiza el temporizador de aparición de enemigos 
    y genera enemigos cuando la cantidad total de enemigos es menor que el máximo*/

    if (this->enemies.size() < this->maxEnemy) {
        if (this->enemySpawnTimer>=this->enemySpawnTimerMax) {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    //Move the enemies
    for(int i = 0 ; i<enemies.size();i++){
        bool deleted = false;
        //move
        this->enemies[i].move(0.f, 1.f);
        //Check if clicked upon
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                deleted = true;
                //win point
                this->points += 10.f;
            }
        }
        //Out Screen
        if (this->enemies[i].getPosition().y > this->window->getPosition().y)
            deleted = true;
        //Delete  Enemy
        if (deleted)
            this->enemies.erase(this->enemies.begin() + i);
    }
}

void gamePlay::drawEnemies()
{
    for (auto& e : this->enemies) {
        this->window->draw(e);
    }
}
