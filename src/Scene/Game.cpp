/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Game
*/

#include "../../include/Scene/Game.hpp"
#include "../../include/Core.hpp"
#include <fstream>
#include <sstream>
#include <streambuf>
#include <iomanip>

std::string fillMap(int level)
{
    std::string filepath = "maps/level" + std::to_string(level);
    filepath += ".enn";
    std::ifstream f(filepath);
    std::stringstream buffer;
    buffer << f.rdbuf();
    return buffer.str();
}

std::vector<sf::RectangleShape> Game::createMap(std::string map)
{
    std::vector<sf::RectangleShape> da;
    sf::Vector2f rectPos;
    rectPos.y = 40;
    sf::RectangleShape rect(sf::Vector2f(79, 79));

    for (int i = 0; map[i] != 0; i++, rectPos.y += 80, rectPos.x = 0)
        for (; map[i] != '\n' && map[i] != 0; i++, rectPos.x += 80)
        {
            if (map[i] == '0') { rect.setPosition(rectPos); rect.setFillColor({255, 255, 255, 0}); da.push_back(rect);}
            else if (map[i] == '1') { rect.setPosition(rectPos); rect.setFillColor(sf::Color::Black); da.push_back(rect); }
            else if (map[i] == '9') { rect.setPosition(rectPos); rect.setFillColor(sf::Color::Blue); da.push_back(rect);_winrect = rect;}
        }
    return da;
}

Game::Game()
{
    _id = 1;
    _level = 1;
    std::string map = fillMap(_level);
    _map = createMap(map);
    _view = true;
    start = false;
    timer = 0;
}

const int Game::getId()
{
    return _id;
}

void Game::run(Core *core)
{
    if (_level == 8) core->switchScene(0);
    maxTimer = (150 * _level / 1.2) / 60; 
    while (core->getWindow().pollEvent(core->getEvent()))
    {
        if (core->getEvent().type == sf::Event::Closed) core->switchScene(-1);

        if (core->getEvent().type == sf::Event::KeyReleased)
            if (core->getEvent().key.code == sf::Keyboard::V) _view = !_view;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            _player.reset();
            start = false;
            _view = true;
            timer = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            _view = false;
            start = true;
        }
        if (start) _player.input(core);
    }
    if (start && _view)
    {
        timer++;
    }
    checkWin(core);
    if (timer >= 150 * _level / 1.2) core->switchScene(-1);
    _player.movement();
    _player.gravity(_map);
    core->getWindow().clear(sf::Color::Magenta);
    if (_view) displayMap(core->getWindow());
    core->getWindow().draw(_player.getPrint());
    printTimer(core);
    core->getWindow().display();
}

void Game::displayMap(sf::RenderWindow& app)
{
    for (int i = 0; i != _map.size(); i++) app.draw(_map[i]);
}

void Game::printTimer(Core *core)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3) << timer/60 << "/" << maxTimer;
    core->printText(ss.str(), {895, 0}, 40, sf::Color::Black);
}

void Game::checkWin(Core *core)
{
    if (_player.getPosition().x < _winrect.getPosition().x + _winrect.getSize().x &&
        _player.getPosition().x + _player.getSize().x > _winrect.getPosition().x &&
        _player.getPosition().y < _winrect.getPosition().y + _winrect.getSize().y &&
        _player.getPosition().y + _player.getSize().y > _winrect.getPosition().y)
    {
        core->playWin();
        _level += 1;
        std::string map = fillMap(_level);
        _map = createMap(map);
        _view = true;
        start = false;
        timer = 0;
        _player.reset();
    }
    if (_player.getPosition().y > 1200)
    {
        core->playFall();
        _player.reset();
        start = false;
        _view = true;
        timer = 0;
    }
}

Game::~Game()
{}