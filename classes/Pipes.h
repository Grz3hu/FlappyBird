//
// Created by grzes on 22.01.2020.
//

#ifndef FLAPPYBIRD_PIPES_H
#define FLAPPYBIRD_PIPES_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameState.h"
#include <stdlib.h>
#include <time.h>

const int SPEED=7;

namespace fb {
    class Pipes {

        sf::Texture tUpperPipe;
        sf::Sprite sUpperPipe[5];
        bool upperCollisions[5];

        sf::Texture tLowerPipe;
        sf::Sprite sLowerPipe[5];
        bool lowerCollisions[5];

        friend class Game;;

        int randPos;

    public:
        Pipes() {
            if (!tUpperPipe.loadFromFile("assets/images/UpperPipe.png")) {
                std::cout << "pipe error";
            }

            if (!tLowerPipe.loadFromFile("assets/images/LowerPipe.png")) {
                std::cout << "pipe error";
            }

            srand(time(NULL));

            for (int i = 0; i < 5; i++) {
                randPos=1+rand()%400;
                sUpperPipe[i].setTexture(tUpperPipe);
                sUpperPipe[i].setPosition(0 + (i + 2) * 490, -450+randPos);
                sLowerPipe[i].setTexture(tLowerPipe);
                sLowerPipe[i].setPosition(0 + (i + 2) * 490, 260+randPos);
                lowerCollisions[i]=true;
                upperCollisions[i]=true;
            }

        }

        void move() {

            for (int i = 0; i < 5; i++) {
                sUpperPipe[i].setPosition(sUpperPipe[i].getPosition().x - SPEED, sUpperPipe[i].getPosition().y);
                sLowerPipe[i].setPosition(sLowerPipe[i].getPosition().x - SPEED, sLowerPipe[i].getPosition().y);

                if (sUpperPipe[i].getPosition().x < -150)
                {
                    randPos=rand()%400;
                    sUpperPipe[i].setPosition(1790+600, -450+randPos);
                    sLowerPipe[i].setPosition(1790+600, 260+randPos);
                    lowerCollisions[i]=true;
                    upperCollisions[i]=true;
                }
            }
        }

        void draw(sf::RenderWindow &window) {
            for (int i = 0; i < 5; i++) {
                window.draw(sUpperPipe[i]);
                window.draw(sLowerPipe[i]);
            }
        }

        void reset()
        {
            for (int i = 0; i < 5; i++) {
                randPos=1+rand()%400;
                sUpperPipe[i].setTexture(tUpperPipe);
                sUpperPipe[i].setPosition(0 + (i + 2) * 490, -450+randPos);
                sLowerPipe[i].setTexture(tLowerPipe);
                sLowerPipe[i].setPosition(0 + (i + 2) * 490, 260+randPos);
                lowerCollisions[i]=true;
                upperCollisions[i]=true;
            }
        }

    };
}

#endif //FLAPPYBIRD_PIPES_H
