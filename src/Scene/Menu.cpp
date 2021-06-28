/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Menu
*/

#include "../../include/Scene/Menu.hpp"
#include "../../include/Core.hpp"

Menu::Menu()
{
    _id = 0;
    img.loadFromFile("asset/name.png");
    title.setTexture(img);
    title.setPosition({610, 150});
    flagT.loadFromFile("asset/flag.png");
    flag.setTexture(flagT);
    flag.setPosition({2, 1046});
    flag.rotate(60);
    _exitButton = new Button(sf::Color::Black, {800, 850}, {250, 100}, "EXIT", sf::Color::White);
    _playButton = new Button(sf::Color::Black, {780, 500}, {320, 100}, "START", sf::Color::White);
    _tutoButton = new Button(sf::Color::Transparent, {1670, 980}, {250, 100}, "TUTO", sf::Color::Black);
}

const int Menu::getId()
{
    return _id;
}

void Menu::run(Core *core)
{
    while (core->getWindow().pollEvent(core->getEvent()))
    {
        if (core->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (_exitButton->isClick(sf::Mouse::getPosition())) core->switchScene(-1);
            else if (_playButton->isClick(sf::Mouse::getPosition())) core->switchScene(1);
            else if (_tutoButton->isClick(sf::Mouse::getPosition())) core->switchScene(2);
        }
    }
    core->getWindow().clear(sf::Color::Green);
    core->getWindow().draw(title);
    _exitButton->print(core);
    _playButton->print(core);
    _tutoButton->print(core);
    core->getWindow().draw(flag);
    core->getWindow().display();
}

Menu::~Menu()
{
}
