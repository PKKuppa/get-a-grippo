#pragma once
#include <SFML/Graphics.hpp>
#include <states/States.hpp>

class Player : public sf::RectangleShape
{
private:
	const float G = 600.f;
	const float FRICTION = 1.f;
	const float JUMP_MODIFIER = -400.f;
	
public:
	enum class Direction { Left = -1, Right = 1 };

	sf::Vector2f velocity = { 0.f,0.f };
	sf::Vector2f acceleration = {FRICTION*velocity.x,G};
	const float horinzontalMoveSpeed = 250.0f;
	States::PlayerState playerState = States::PlayerState::AIRBORNE;

	Player(sf::Vector2f initialPos, sf::Vector2f size, bool showBoundingBox = false);
	void updatePos(float& dt);
	void jump();
	void moveHorizontal(Direction dir);
};

