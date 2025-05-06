#pragma once
#include <classes/platforms/Platform.hpp>
#include <classes/Player.hpp>
#include <SFML/Audio.hpp>
class Level
{
public:
	std::vector<Platform*> platforms;
	Level(std::vector<Platform*> platList, const sf::Vector2f playerStart, sf::Sprite background);
	Level(const std::string filePath,const sf::Vector2f playerStart, sf::Sprite background);
	void checkCollision(Player& player);
	sf::Sprite backgroundImg;
	sf::Music levelMusic;
	void setMusic(const std::string filePath);
	void resetPlayerPos(Player& player);
private:
	const sf::Vector2f playerStartPosition;
	const float PLATFORM_PUSHBACK = 2.0f;
	void handleCollision(Player& player, const sf::FloatRect& intersection, int i);

};

