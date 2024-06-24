#include "gamePlay.h"
#include <Windows.h>
#include <iostream>

gamePlay::gamePlay()
{
    this->initialVariables();
    this->initWindows();
}

gamePlay::~gamePlay()
{
	delete this->window;
}

void gamePlay::update()
{
    this->updateEvent();
}

void gamePlay::render(){
    // Clear - Render - Display 
    this->window->clear(sf::Color(255,0,0,255));
    //this->window->clear();
    this->window->display();
}
//======    ACCESSORS    ======
const bool gamePlay::runnig() const { 	
    return this->window->isOpen();
}
//======    INIT    ======
void gamePlay::initialVariables(){
	this->window = nullptr;
}

void gamePlay::initWindows(){
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "GAME - RUN", sf::Style::Titlebar | sf::Style::Close);
}
//======    UPDATE    ======
void gamePlay::updateEvent()
{
    while (this->window->pollEvent(this->event));
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape) {
                
                this->window->close();

            }
            break;
        }
    }
}

