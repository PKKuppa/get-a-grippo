#include "view/MenuOption.hpp"

MenuOption::MenuOption(std::string text) : sf::RectangleShape(defaultSize)
{
	this->text.setString(text);

	sf::RectangleShape::setFillColor(sf::Color::Red);
	sf::RectangleShape::setOutlineColor(sf::Color::White);
	sf::RectangleShape::setOutlineThickness(10.f);
}
