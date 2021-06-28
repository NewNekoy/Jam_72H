/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"
#include "../Player.hpp"
#include <vector>

class Game : public Scene
{
    public:
        Game();
        ~Game();

        void run (Core *core);
        const int getId();
        void displayMap(sf::RenderWindow& app);
        void printTimer(Core *core);
        void checkWin(Core *core);
        std::vector<sf::RectangleShape> createMap(std::string map);

    protected:
    private:
        int _id;
        int _level;
        std::vector<sf::RectangleShape> _map;
        Player _player;
        bool _view;
        bool start;
        int timer;
        int maxTimer;
        sf::RectangleShape _winrect;

};

#endif /* !GAME_HPP_ */
