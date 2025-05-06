#pragma once
#include <SFML/Graphics.hpp>

std::unique_ptr<sf::Shape> createShapePtr(sf::Shape& original);
void processShape(sf::Shape& shape, const sf::Texture* texture, const sf::Vector2f intialPos, const sf::Transform transform);

