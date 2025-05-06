#include "classes/platforms/Platform.hpp"
#include <utilFunctions.hpp>
#include <iostream>
Platform::Platform(sf::Shape& s, const sf::Texture *texture, const sf::Vector2f intialPos, const  sf::Transform transform)
{	
	//shape.setFillColor(sf::Color::Magenta);
	shape = createShapePtr(s);
	processShape(*shape, texture, intialPos, transform);
}

Platform::Platform(Platform& other, const sf::Vector2f intialPos, const sf::Transform transform, const sf::Texture* texture)
{	
	shape = createShapePtr(*(other.shape));
	//shape->setFillColor(sf::Color::Magenta);
	processShape(*shape, texture , intialPos, transform);
	//std::cout << shape->getPosition().x << std::endl;
}

sf::FloatRect Platform::getGlobalBounds()
{
	return shape->getGlobalBounds();
}


