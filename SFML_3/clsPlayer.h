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
	void upDate();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setY(int ,int);

};

