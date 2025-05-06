
#include <SFML/Graphics.hpp>
#include <classes/Player.hpp>
#include <classes/platforms/Platform.hpp>
#include <iostream>
#include <classes/levels_types/Level.hpp>
#include <Controller.hpp>
#include <Renderer.hpp>




int main()
{
    /*
    * SETTING UP
    */
    const sf::Vector2u RESOLUTION = { 1920,1080 };
    const std::string GAME_TITLE = "GET A GRIPPO!";

    sf::RenderWindow window(sf::VideoMode(RESOLUTION), GAME_TITLE);
    Player player({ 100.f,100.f }, { 10.f,25.f });


    sf::Texture texture("./assets/textures/BIGSQUARES.png");
    texture.setRepeated(true);
    sf::RectangleShape rect({ 500.f,50.f });
    Platform plat(rect, &texture, { 250.f,200.f });
    Platform plat2(plat, { 1000.f,800.f });
    Platform plat4(plat, { 500.f,500.f });

    sf::RectangleShape rect3({ 50.f,50.f });
    Platform plat3(rect3, &texture, { 250.f,150.f });
    Platform plat5(plat3, { 700.f,700.f });
    Platform plat6(plat3, { 900.f,600.f });
    std::vector<Platform*> platList = { &plat,&plat2, &plat3, &plat4 };
    platList.push_back(&plat5);
    platList.push_back(&plat6);

    sf::Texture backgroundTexture("./assets/backgrounds/citybg3.jpg");
    sf::Sprite background(backgroundTexture);
    Level testLevel(platList, { 50.f,50.f }, background);
    testLevel.setMusic("./assets/music/DUST.ogg");

    /*
    * 
    * GAME LOOP
    * 
    */




    Controller gameController(player);
    gameController.setLevel(&testLevel);
    Renderer gameRenderer(player,gameController.currentState, window, gameController.getLevel());
    sf::Clock deltaClock;
    //Game Loop
    while (window.isOpen())
    {   
        float dt = deltaClock.restart().asSeconds();
        //Event Loop
        gameController.update(dt);
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            gameController.handleEvents(event);
              
        }

        window.clear();
        gameRenderer.draw();
        window.display();
    }
}