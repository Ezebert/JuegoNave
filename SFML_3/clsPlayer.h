#pragma once
#include <SFML/Graphics.hpp>
class clsPlayer : public sf::Drawable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
public:
	clsPlayer();
	clsPlayer(int, int); // Contructor setX() and setY()
	void upDate(); //Actualizar
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //Dibujar
protected:
	void isPress(); // Tecla Presionada
	void controlExtreme();// Controla los extremos de la pantalla
};

