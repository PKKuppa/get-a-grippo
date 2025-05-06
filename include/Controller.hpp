#pragma once
#include <states/States.hpp>
#include <SFML/Graphics.hpp>
#include<classes/Player.hpp>
#include<classes/levels_types/Level.hpp>

class Controller
{
public:
	 States::GameState currentState;
	 void handleEvents(const std::optional<sf::Event>& event);
	 Controller(Player& player, States::GameState startState = States::GameState::MENU);
	 void update(float& dt);
	 void setLevel(Level* level);
	 Level*& getLevel();

private:
	void handleInLevelEvents(const std::optional<sf::Event>& event);
	void updateLevel(float& dt);
	Player& player;
	Level* currLevel;
};

