/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Button
*/

#include "../include/Button.hpp"
#include "../include/Core.hpp"

Button::Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, std::string e, sf::Color textColor)
{
    if (e != "")
        _text = e;
    _pos = pos;
    _size = size;
    _color = color;
    _textColor = textColor;
    _rect.setPosition(pos);
    _rect.setSize(size);
    _rect.setFillColor(color);
}

void Button::setText(std::string text)
{
    _text = text;
}

bool Button::isClick(sf::Vector2i mousePos)
{
    sf::Vector2f news;
    news.x = (float)mousePos.x;
    news.y = (float)mousePos.y;

    if (news.x >= _pos.x && news.x <= (_pos.x + _size.x) &&
    news.y >= _pos.y && news.y <= (_pos.y + _size.y))
        return true;
    else 
        return false;
}

void Button::print(Core *core)
{
    core->getWindow().draw(_rect);
    core->printText(_text, {_pos.x + 45, _pos.y}, 75, _textColor);
}

float const Button::getX()
{
    return _pos.x;
}

float const Button::getY()
{
    return _pos.y;
}

float const Button::getWidth()
{
    return _size.y;
}

float const Button::getHeight()
{
    return _size.x;
}

Button::~Button()
{
}
