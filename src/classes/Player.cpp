#include "classes/Player.hpp"
#include <algorithm>

Player::Player(sf::Vector2f initialPos, sf::Vector2f size, bool showBoundingBox) : sf::RectangleShape(size) {
	RectangleShape::setPosition(initialPos);
	RectangleShape::setFillColor(sf::Color::Transparent);
	RectangleShape::setOutlineColor(sf::Color::Cyan);
	RectangleShape::setOutlineThickness(2.5f);
	RectangleShape::setOrigin({ size.x / 2,size.y / 2 });
}

void Player::updatePos(float &dt) {
	if (playerState == States::PlayerState::AIRBORNE) {
		acceleration.y = G;
	}
	else {
		acceleration.y = 0;
	}
	RectangleShape::move({dt*velocity.x,dt*velocity.y});
	velocity += {acceleration.x* dt, acceleration.y* dt};
}

void Player::jump() {
	if (playerState != States::PlayerState::AIRBORNE) {
		velocity.y += JUMP_MODIFIER;
		playerState = States::PlayerState::AIRBORNE;
	}

}

void Player::moveHorizontal(Direction dir)
{
	velocity.x = static_cast<int>(dir) * horinzontalMoveSpeed;
}

