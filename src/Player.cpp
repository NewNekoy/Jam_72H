/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Player
*/

#include "../include/Player.hpp"
#include "../include/Core.hpp"
#include <iostream>

Player::Player()
{
    _pos = {100, 765};
    _size = {48, 70};
    tp.loadFromFile("asset/walk.png");
    _char.setTexture(tp);
    _char.setPosition(_pos);
    rectsource = {0, 0, 48, 70};
    _char.setTextureRect(rectsource);
    right = false;
    left = false;
    inJump = false;
    fall = true;
}

sf::Sprite Player::getPrint()
{
    _char.setTextureRect(rectsource);
    _char.setPosition(_pos);
    return _char;
}

void Player::input(Core *core)
{
    right = false;
    left = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        left = false;
        right = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        right = false;
        left = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _char.move(0, 10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !fall && !inJump)
    {
        core->playJump();
        rememJump = _pos.y - 120;
        inJump = true;
    }
    _pos = _char.getPosition();
}

void Player::movement()
{
    if (left){_char.move(-10, 0);_char.setScale(-1.f, 1.f);}
    if (right){_char.move(10, 0);_char.setScale(1.f, 1.f);}
    _pos = _char.getPosition();
}

void Player::gravity(std::vector<sf::RectangleShape> map)
{
    if (clock.getElapsedTime().asSeconds() > 0.01f)
    {
        if (rectsource.left == 288 - 48)
            rectsource.left = 0;
        else
            rectsource.left += 48;
        clock.restart();
    }

    fall = true;
    if (!inJump)
    {
        for (int i = 0; i < map.size(); i++)
        {
            if (_pos.y + _size.y >= map[i].getPosition().y && _pos.y + _size.y <= map[i].getPosition().y + 15
            && map[i].getFillColor() == sf::Color::Black
            && _pos.x >= map[i].getPosition().x
            && _pos.x <= (map[i].getPosition().x + map[i].getSize().x)
            or
            _pos.y + _size.y >= map[i].getPosition().y && _pos.y + _size.y <= map[i].getPosition().y + 15
            && map[i].getFillColor() == sf::Color::Black
            && _pos.x  + _size.x >= map[i].getPosition().x
            && _pos.x  + _size.x <= (map[i].getPosition().x + map[i].getSize().x))
            {
                fall = false;
                _char.setPosition({_char.getPosition().x, map[i].getPosition().y - _size.y});
            }
        }
        if (fall) _char.move(0, 12);
    }
    else
    {
        if (_pos.y <= rememJump) {inJump = false; fall = true;}
        else _char.move(0, -10);
    }
    _pos = _char.getPosition();

}

sf::Vector2f Player::getPosition()
{
    return _char.getPosition();
}

sf::Vector2f Player::getSize()
{
    return {48, 70};
}

void Player::reset()
{
    _pos = {100, 765};
    _size = {40, 70};
    _char.setPosition(_pos);
    right = false;
    left = false;
    inJump = false;
    fall = true;
}

Player::~Player()
{
}