#pragma once
#include <SFML/Graphics.hpp>
class clsAsteroide : public sf::Drawable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	float _vel;
public:
	clsAsteroide();
	clsAsteroide(int x);
	void upDate();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	void createRandom();


};

