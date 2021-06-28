/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>

class Core;

class Player {
    public:
        Player();
        ~Player();

        sf::Sprite getPrint();
        void input(Core *core);
        void movement();
        void gravity(std::vector<sf::RectangleShape> map);
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        void reset();

    protected:
    private:
        sf::Vector2f _pos;
        sf::Vector2f _size;
        sf::Texture tp;
        sf::Sprite _char;
        sf::IntRect rectsource;
        bool left, right, inJump, fall;
        float rememJump;
        sf::Clock clock;
};

#endif /* !PLAYER_HPP_ */
