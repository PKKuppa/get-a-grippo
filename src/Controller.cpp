#include "Controller.hpp"

void Controller::handleEvents(const std::optional<sf::Event>& event)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::I) {
            this->currentState = States::GameState::IN_LEVEL;
        }
    }
	if (currentState == States::GameState::IN_LEVEL) {
		handleInLevelEvents(event);
	}
}

Controller::Controller(Player& player, States::GameState startState)
    :player(player)
{
    this->currLevel = nullptr;
    this->currentState = startState;
}

void Controller::handleInLevelEvents(const std::optional<sf::Event>& event)
{
    //Player movement
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::Space) {
            player.jump();
        }
        if (keyPressed->scancode == sf::Keyboard::Scan::A) {
            player.velocity.x = -1 * player.horinzontalMoveSpeed;
        }
        if (keyPressed->scancode == sf::Keyboard::Scan::D) {
            player.velocity.x = player.horinzontalMoveSpeed;
        }
    }
    //Player stopping
    if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
        if (keyReleased->scancode == sf::Keyboard::Scan::A) {
            player.velocity.x = 0;
        }
        if (keyReleased->scancode == sf::Keyboard::Scan::D) {
            player.velocity.x = 0;
        }
    }
}

void Controller::update(float& dt)
{
    if (currentState == States::GameState::IN_LEVEL) {
        updateLevel(dt);
    }
}

void Controller::setLevel(Level* level)
{
    currLevel = level;
}

 Level*& Controller::getLevel()
{
    return currLevel;
}

// Update while in level
void Controller::updateLevel(float& dt)
{
    player.updatePos(dt);
    currLevel->checkCollision(player);
    currLevel->resetPlayerPos(player);
}

