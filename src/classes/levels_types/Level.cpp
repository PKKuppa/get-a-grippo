#include "classes/levels_types/Level.hpp"
#include <iostream>

Level::Level(std::vector<Platform*> platList,const sf::Vector2f playerStart, sf::Sprite background):
	backgroundImg(background), playerStartPosition(playerStart)
{
	platforms = platList;
}

Level::Level(const std::string filePath,const sf::Vector2f playerStart, sf::Sprite background) :
	backgroundImg(background), playerStartPosition(playerStart)
{
}

void Level::checkCollision(Player& player)
{
	int index = -1;
	for (int i = 0; i < platforms.size();i++) {
		Platform* plat = platforms[i];
		if (const std::optional<sf::FloatRect> intersection = plat->getGlobalBounds().findIntersection(player.getGlobalBounds())) {
			index = i;
			handleCollision(player, *intersection, index);
		}
	}
	if (index == -1) {
		player.playerState = States::PlayerState::AIRBORNE;
	}
}

void Level::setMusic(const std::string filePath)
{
	levelMusic.openFromFile(filePath);
	levelMusic.setLooping(true);
	levelMusic.setVolume(15.f);
}

void Level::resetPlayerPos(Player& player)
{
	sf::Vector2f playerPos = player.getPosition();
	if (playerPos.x > 1920 || playerPos.y > 1080) {
		player.setPosition(playerStartPosition);
		player.velocity = { 0.f,0.f };
	}
}


void Level::handleCollision(Player& player, const sf::FloatRect& intersection, int i)
{
	//SIDE COLLISION
	Platform* plat = platforms[i];
	if (intersection.size.x < intersection.size.y) {
		player.velocity.x = 0.0f;
		//LEFT
		if (player.getPosition().x < plat->shape->getPosition().x) {
			player.move({ -1.f * PLATFORM_PUSHBACK,0.f });
		}
		//RIGHT
		else {
			player.move({PLATFORM_PUSHBACK,0.f });
		}
		
	}
	//VERTICAL COLLISION
	else {
		player.playerState = States::PlayerState::GROUNDED;
		player.velocity.y = 0.0f;
	}
	
	
	
}
