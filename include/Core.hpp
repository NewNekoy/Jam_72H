/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Scene/Menu.hpp"
#include "Scene/Tuto.hpp"
#include "Scene/Game.hpp"

/*

0 - Menu
1 - Game
2 - Tutorial
-1 - Leave

*/

class Core {
    public:
        Core();
        ~Core();

        void run();
        sf::RenderWindow& getWindow();
        sf::Event& getEvent();
        void switchScene(int id);
        void printText(std::string str, sf::Vector2f vec, int charSize = 50, sf::Color = sf::Color::White);
        void useSave();
        void close();
        void playJump();
        void playWin();
        void playFall();

    protected:
    private:
        sf::RenderWindow _app;
        std::vector<Scene*> _scene;
        sf::Event _event;

        sf::Font _font;
        sf::Text _text;

        sf::Music *_mainMusic;
        sf::Music *_jump;
        sf::Music *_win;
        sf::Music *_fall;
};

#endif /* !CORE_HPP_ */
