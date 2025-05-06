#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
class Platform
{
public:
	std::unique_ptr<sf::Shape> shape;
	Platform(sf::Shape& s,const sf::Texture* texture, const sf::Vector2f intialPos, const sf::Transform transform = sf::Transform::Identity);
	Platform(Platform& other, const sf::Vector2f intialPos, const sf::Transform transform = sf::Transform::Identity, const sf::Texture* texture = nullptr);
	sf::FloatRect getGlobalBounds();
};

