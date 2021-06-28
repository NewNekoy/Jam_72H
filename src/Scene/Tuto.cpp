/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Tuto
*/

#include "../../include/Scene/Tuto.hpp"
#include "../../include/Core.hpp"

Tuto::Tuto()
{
    _id = 2;
}

const int Tuto::getId()
{
    return _id;
}

void Tuto::run(Core *core)
{
    while (core->getWindow().pollEvent(core->getEvent()))
    {
        if (core->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) core->switchScene(0);
    }
    core->getWindow().clear(sf::Color::Black);
    core->printText("Hello, you will play as the smallest of the knights who must escape.\nWhere ? I don't know how to make your brain work!\nThe black blocks are solid and the finish is blue !\nGood Luck (It's our first game Jam,\nso just take pleasure and don't mind other things!)\nFor the two side, we make the block disapear and you need\nto remind you where there are to finish the level!\nYou have Timer with how mutch time you can see the blocks!\nKeyBoard : Q = go Left, D = go Right, R = restart level, V = make block appear!\nThere is 7 diferent level! Good luck!", {50, 50});
    core->printText("Press ESC to back", {0, 995});
    core->getWindow().display();
}

Tuto::~Tuto()
{
}
