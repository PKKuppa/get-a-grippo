#pragma once
#include <SFML/Graphics.hpp>
class MenuOption : sf::RectangleShape
{
public:
	MenuOption(std::string text);
	virtual void menuAction();
private:
	const sf::Vector2f defaultSize = { 50,250 };
	sf::Text text;
};

