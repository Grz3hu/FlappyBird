//
// Created by grzes on 22.01.2020.
//

#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

const int MINUS=8; //8
const int PLUS=7; //7

namespace fb {
    class Bird {
        float posx;
        float posy;

        sf::Sprite sBird;
        sf::Texture tBird;

        sf::SoundBuffer soundBufferJump;
        sf::Sound soundJump;

        friend class Game;

    public:
        void jump() {

            if (posy > 3) {
                soundJump.setBuffer(soundBufferJump);
                soundJump.play();
                posy -= MINUS;
            }
        }

        void fall() {
            if(posy<622)
                posy+=PLUS;
        }

        void draw(sf::RenderWindow& window) {
            sBird.setPosition(posx,posy);
            window.draw(sBird);
        }

        void reset()
        {
            posy=400.0;
            posx=105.0;
        }

        Bird()
        {

            posy=400.0;
            posx=105.0;


            if (!tBird.loadFromFile("assets/images/bird.png"))
            {
                std::cout << "bird error";
            }
            sBird.setTexture(tBird);

            if (!soundBufferJump.loadFromFile("assets/sounds/jump.wav"))
                std::cout << "jump sound error";
        }
    };

};


#endif //FLAPPYBIRD_BIRD_H
