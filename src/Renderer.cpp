#include "Renderer.hpp"

Renderer::Renderer(Player& player, States::GameState& controllerState, sf::RenderWindow& window, Level*& currLevel):
player(player), currState(controllerState), window(window), currLevel(currLevel){ 
	initLevel();
}

void Renderer::draw()
{
	if (currState == States::GameState::IN_LEVEL) {
		drawInLevel();
	}
}

void Renderer::initLevel()
{
	currLevel->levelMusic.play();
}

void Renderer::drawInLevel()
{	
	window.draw(currLevel->backgroundImg);
	window.draw(player);
	for (Platform* plat : currLevel->platforms) {
		window.draw(*(plat->shape));
	}
}



