//
// Created by grzes on 22.01.2020.
//

#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <fstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Bird.h"
#include "Pipes.h"
#include "GameState.h"
#include "Collision.hpp"

namespace fb {
    class Game {
        GameState state;
        sf::Texture tBackground;
        sf::Sprite sBackground;
        sf::Texture tHeart;
        sf::Sprite sHeart;
        sf::Texture tLogo;
        sf::Sprite sLogo;
        sf::Texture tGameOver;
        sf::Sprite sGameOver;
        sf::SoundBuffer soundBufferPoint;
        sf::Sound soundPoint;
        sf::SoundBuffer soundBufferDeath;
        sf::Sound soundDeath;
        sf::Font font;
        sf::Text scoreText;
        unsigned int lifes;
        unsigned long long int score;
        int record;

    public:
        Game() {
            if (!tBackground.loadFromFile("assets/images/background.jpg")) {
                std::cout << "background error" << std::endl;
            }
            sBackground.setTexture(tBackground);

            if(!tHeart.loadFromFile("assets/images/heart.png")) {
                std::cout << "heart error";
            }
            sHeart.setTexture(tHeart);

            if(!tLogo.loadFromFile("assets/images/logo.png")) {
                std::cout << "logo error";
            }
            sLogo.setTexture(tLogo);
            sLogo.setPosition(240,127);

            if(!tGameOver.loadFromFile("assets/images/gameover.png")) {
                std::cout << "gameover error";
            }
            sGameOver.setTexture(tGameOver);
            sGameOver.setPosition(390,127);

            if (!soundBufferPoint.loadFromFile("assets/sounds/point.wav")) {
                std::cout << "point sound error";
            }

            if (!soundBufferDeath.loadFromFile("assets/sounds/death.wav")) {
                std::cout << "death sound error";
            }

            if (!font.loadFromFile("assets/fonts/8bit.ttf"))
            {
                std::cout << "font error";
            }
            scoreText.setFont(font);
            scoreText.setCharacterSize(24);
            scoreText.setPosition(5,5);
            scoreText.setFillColor(sf::Color::White);

            lifes=3;
            score=0;

            std::ifstream inputFile("save/record.txt");
            inputFile >> record;
            inputFile.close();
        }

        void check(fb::Bird &bird, fb::Pipes &pipes)
        {
            for(int i=0;i<5;i++)
            {

                if(pipes.upperCollisions[i] && Collision::PixelPerfectTest(bird.sBird,pipes.sUpperPipe[i])) {
                    pipes.upperCollisions[i]=false;
                    soundDeath.setBuffer(soundBufferDeath);
                    soundDeath.play();
                    collision();
                }
                else
                if(pipes.lowerCollisions[i] && Collision::PixelPerfectTest(bird.sBird,pipes.sLowerPipe[i])) {
                    pipes.lowerCollisions[i]=false;
                    soundDeath.setBuffer(soundBufferDeath);
                    soundDeath.play();
                    collision();
                }
                else
                if(pipes.sLowerPipe[i].getPosition().x<150.0 && pipes.sLowerPipe[i].getPosition().x>140.0)
                {
                    soundPoint.setBuffer(soundBufferPoint);
                    soundPoint.play();
                    score++;
                    if(score>record) record=score;
                }
            }
        }

        void drawBackground(sf::RenderWindow &window) {
            window.draw(sBackground);
        }

        void drawScore(sf::RenderWindow &window) {
            scoreText.setString("Score "+std::to_string(score));
            window.draw(scoreText);
        }

        void drawRecord(sf::RenderWindow &window) {
            scoreText.setString("Record "+std::to_string(record));
            window.draw(scoreText);
        }

        void saveRecord(){
            std::ofstream outputFile("save/record.txt");
            outputFile << record;
            outputFile.close();
        }

        void drawLifes(sf::RenderWindow &window) {
            for(unsigned int i=0;i<lifes;i++)
            {
                sHeart.setPosition(5+(i*55),34);
                window.draw(sHeart);
            }
        }

        void drawLogo(sf::RenderWindow &window) {
            window.draw(sLogo);
        }

        void drawGameOver(sf::RenderWindow &window){
            window.draw(sGameOver);
        }

        int getLifes() {
            return lifes;
        }

        void collision()
        {
            lifes--;
            if(lifes==0) {
                state = GAMEOVER;
            }
        }

        void setState(fb::GameState newState)
        {
            state=newState;
        }

        void reset()
        {
            lifes=3;
            score=0;
        }

        fb::GameState getState()
        {
            return state;
        }
    };
};

#endif //FLAPPYBIRD_GAME_H
