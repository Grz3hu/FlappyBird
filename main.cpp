#include <SFML/Graphics.hpp>
#include "classes/Bird.h"
#include "classes/Game.h"
#include "classes/Pipes.h"
#include <unistd.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Flappy Bird",sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(50);

    fb::Bird bird;
    fb::Game game;
    fb::Pipes pipes;

    game.setState(fb::MENU);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                game.saveRecord();
                window.close();
            }
        }

        if(game.getState()==fb::MENU) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                game.setState(fb::GAME);
        }

        if(game.getState()==fb::GAME) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                bird.jump();
            else
                bird.fall();

            game.check(bird, pipes);
            pipes.move();
        }
        window.clear();

        game.drawBackground(window);
        bird.draw(window);
        pipes.draw(window);
        if(game.getState()==fb::GAME) {
            game.drawScore(window);
            game.drawLifes(window);
        }
        if(game.getState()==fb::GAMEOVER)
        {
            game.reset();
            bird.reset();
            pipes.reset();
            game.drawGameOver(window);
            game.setState(fb::MENU);
            window.display();
            sleep(2);
        }
        if(game.getState()==fb::MENU){
            game.drawRecord(window);
            game.drawLogo(window);
        }
        window.display();
    }

    return 0;
}
