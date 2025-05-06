#include "utilFunctions.hpp"
#include <iostream>


std::unique_ptr<sf::Shape> createShapePtr(sf::Shape &original) {

	if (auto rect = dynamic_cast<sf::RectangleShape*>(&original)) {
		sf::RectangleShape copy(rect->getSize());
		copy.setTexture(original.getTexture());
		return std::make_unique<sf::RectangleShape>(copy);
	}
	else if (auto circle = dynamic_cast<sf::CircleShape*>(&original)) {
		sf::CircleShape copy(circle->getRadius(), circle->getPointCount());
		copy.setTexture(original.getTexture());
		return std::make_unique<sf::CircleShape>(copy);
	}
	else if (auto convex = dynamic_cast<sf::ConvexShape*>(&original)) {
		sf::CircleShape copy(convex->getPointCount());
		copy.setTexture(original.getTexture());
		return std::make_unique<sf::CircleShape>(copy);
	}
	return nullptr;
}

void processShape(sf::Shape& shape, const sf::Texture* texture, const sf::Vector2f intialPos, const sf::Transform transform) {

	if (texture) {
		shape.setTexture(texture);
	}
	shape.setPosition(intialPos);
	shape.setOrigin(shape.getGeometricCenter());
	//need to apply transform
}

