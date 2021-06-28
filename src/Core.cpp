/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Core
*/

#include "../include/Core.hpp"

Core::Core()
{
    _app.create(sf::VideoMode(1920, 1080), "Enn", sf::Style::Fullscreen);
    _app.setFramerateLimit(60);
    _scene.push_back(new Menu());
    _scene.push_back(new Game());
    _scene.push_back(new Tuto());
    _font.loadFromFile("asset/arial.ttf");
    _text.setFont(_font);
    _mainMusic = new sf::Music();
    _mainMusic->openFromFile("asset/mainMusic.ogg");
    _mainMusic->setVolume(16);
    _mainMusic->play();
    _jump = new sf::Music();
    _jump->openFromFile("asset/jump.ogg");
    _jump->setVolume(20);
    _win = new sf::Music();
    _win->openFromFile("asset/win.ogg");
    _win->setVolume(20);
    _fall = new sf::Music();
    _fall->openFromFile("asset/fall.ogg");
    _fall->setVolume(20);
}

sf::RenderWindow& Core::getWindow()
{
    return _app;
}

sf::Event& Core::getEvent()
{
    return _event;
}

void Core::switchScene(int id)
{
    if (id == -1) {close();}
    for (int i = 0; i < _scene.size(); i++)
    {
        if (_scene[i]->getId() == id)
        {
            std::swap(_scene[0], _scene[i]);
            return ;
        }
    }
}

void Core::run()
{
    while (_app.isOpen()) _scene[0]->run(this);
    close();
}

void Core::printText(std::string str, sf::Vector2f vec, int charSize, sf::Color color)
{
    _text.setFillColor(color);
    _text.setString(str);
    _text.setCharacterSize(charSize);
    _text.setPosition(vec);
    _app.draw(_text);
}

void Core::useSave()
{

}

void Core::playJump()
{
    _jump->stop();
    _jump->play();
}

void Core::playWin()
{
    _win->stop();
    _win->play();
}

void Core::playFall()
{
    _fall->stop();
    _fall->play();
}

void Core::close()
{
    _mainMusic->stop();
    delete _mainMusic;
    delete _jump;
    delete _win;
    delete _fall;
    _app.close();
    exit(0);
}

Core::~Core()
{
}
