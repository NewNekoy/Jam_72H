/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Core;
class Button;

class Scene {
    public:
        Scene();
        ~Scene();

        virtual void run(Core *core);
        virtual const int getId();

    protected:
    private:
};

#endif /* !SCENE_HPP_ */
