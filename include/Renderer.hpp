#pragma once
#include<states/States.hpp>
#include <classes/levels_types/Level.hpp>
#include <classes/Player.hpp>

class Renderer
{
public:
	Renderer(Player& player, States::GameState& controllerState, sf::RenderWindow& window, Level*& currLevel);
	void draw();


private:
	States::GameState& currState;
	Player& player;
	Level*& currLevel;
	sf::RenderWindow& window;
	void initLevel();
	void drawInLevel();
};

