/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Core;

class Button {
    public:
        Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, std::string e = "", sf::Color textColor = sf::Color::White);
        ~Button();

        bool isClick(sf::Vector2i mousePos);
        void print(Core *core);
        const float getWidth();
        const float getHeight();
        const float getX();
        const float getY();
        void setText(std::string text);

    protected:
    private:
        sf::RectangleShape _rect;
        sf::Vector2f _pos;
        sf::Vector2f _size;
        sf::Color _color;
        sf::Color _textColor;
        std::string _text;
};

#endif /* !BUTTON_HPP_ */
