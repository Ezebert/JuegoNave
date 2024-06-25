#include "gamePlay.h"
#include <Windows.h>
#include <iostream>
#include <sstream>.

gamePlay::gamePlay()
{
    this->initVariables();
    this->initWindows();
    this->initEnemy();
    this->initFonts();
    this->initText();
}

gamePlay::~gamePlay()
{
	delete this->window;
}
//======    SETS    ======
void gamePlay::setPoints(float p)
{
    this->points = p;
}

//======    GETS    ======
float gamePlay::getPoints()
{
    return this->points;
}
//======    FUNCIONES    ======
void gamePlay::update()
{
  this->updateEvent(); //PoolEvents

  if (!this->endGame) {
      this->updateMousePosition();
      this->updateEnemy();
      this->updateText();
  }
  
  
  //End Game condition
  if (this->health <= 0)
      this->endGame = true;

}

void gamePlay::render(){
    // Clear - Render(draw) - Display 
    this->window->clear();
    //Draw obj
    //this->window->draw(this->enemy);
    this->drawEnemies(*this->window);
    this->drawText(*this->window);
    this->window->display();
}

//======    ACCESSORIOS    ======
const bool gamePlay::runnig() const {
    return this->window->isOpen();
}

const bool gamePlay::getEndGame() const
{
    return this->endGame;
}

//======    FUNCIONES AUX    ======
void gamePlay::spawnEnemy()
{
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
//        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
            );

    int type = rand() % 4;//(0-3)
    switch (type)
    {
    case 1:
        this->enemy.setSize(sf::Vector2f(100.f, 100.f));
        this->enemy.setFillColor(sf::Color::Cyan);//cuerpo
        break;
    case 2:
        this->enemy.setSize(sf::Vector2f(30.f, 30.f));
        this->enemy.setFillColor(sf::Color::Red);//cuerpo
        break;
    case 3:
        this->enemy.setSize(sf::Vector2f(50.f, 50.f));
        this->enemy.setFillColor(sf::Color::Yellow);//cuerpo
        break;
    case 0:
        this->enemy.setSize(sf::Vector2f(70.f, 70.f));
        this->enemy.setFillColor(sf::Color::Green);//cuerpo
        break;
    }
    //Add enemy 
    this->enemies.push_back(this->enemy);
}
//======    INIT    ======
void gamePlay::initVariables(){
	this->window = nullptr;
    //Game Logic
    this->endGame = false;
    this->health = 100;
    this->points=0;
    this->enemySpawnTimerMax = 20.f;;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemy = 5;
    this->mouseHead = false;

}
void gamePlay::initWindows(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "GAME - RUN", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}
void gamePlay::initFonts()
{
    if (this->font.loadFromFile("../font/SPACE.ttf")) {
        std::cout<< " ERROR::GAME::InitFont";
    }
}
void gamePlay::initText()
{
    this->text.setFont(this->font);
    this->text.setCharacterSize(15);//Max de caracteres
    this->text.setFillColor(sf::Color::White);
    this->text.setString("N/D");
}
void gamePlay::initEnemy()
{
    this->enemy.setPosition(20.f,10.f);//(x , y)
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f)); //reduce tamaño
    this->enemy.setFillColor(sf::Color::White);//cuerpo
    this->enemy.setOutlineColor(sf::Color::Green);//contorno
    this->enemy.setOutlineThickness(1.f); // Grosor del contorno
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
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << " \n";
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
        //move
        this->enemies[i].move(0.f, 5.f);
        //Out Screen
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
            //lost point
            this->setPoints(this->getPoints() - 10.f);
            this->health -= 1;;
            std::cout << " Points: \t" << this->getPoints() << " health: \t" << this->health << "\n ";

        }
    }//Fin de For Enemies_Move

    //Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!this->mouseHead) {
            this->mouseHead = true;
            bool deleted = false;
            for (size_t i = 0; i < enemies.size() && !deleted; i++)
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    
                    //win point
                    if(this->enemies[i].getFillColor()==sf::Color::Cyan)
                        this->setPoints(this->getPoints() + 30.f);
                    else if (this->enemies[i].getFillColor() == sf::Color::Green)
                        this->setPoints(this->getPoints() + 50.f);
                    else if (this->enemies[i].getFillColor() == sf::Color::Yellow)
                        this->setPoints(this->getPoints() + 70.f);
                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                        this->setPoints(this->getPoints() + 100.f);
                    //std::cout << " Points: \t" << this->getPoints() << " health: \t" << this->health << "\n ";
                    
                    //Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                }
        }
    }
    else {
        this->mouseHead = false;

    }
    //Delete  Enemy   
}
void gamePlay::updateText()
{
    std::stringstream ss;
    ss << "Points: " << this->getPoints()<< "\n"
        <<"Health: "<<this->health<<"\n";
    this->text.setString(ss.str());
}

//======    DRAW    ======
void gamePlay::drawEnemies(sf::RenderTarget& target)
{
    for (auto& e : this->enemies) {
        target.draw(e);
    }
}

void gamePlay::drawText(sf::RenderTarget& target)
{
    target.draw(this->text);
}
