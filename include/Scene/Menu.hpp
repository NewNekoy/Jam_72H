/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"
#include <vector>

class Menu : public Scene
{
    public:
        Menu();
        ~Menu();

        void run(Core *core);
        const int getId();

    protected:
    private:
        int _id;
        sf::Texture img, flagT;
        sf::Sprite title, flag;
        Button *_exitButton, *_playButton;
        Button *_tutoButton;
};

#endif /* !MENU_HPP_ */
