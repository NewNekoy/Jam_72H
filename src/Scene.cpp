/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Scene
*/

#include "../include/Scene.hpp"

Scene::Scene()
{
}

void Scene::run(Core *core)
{
    std::cout << "instance not create in you're sub-class" << std::endl;
}

const int Scene::getId()
{
    return -1;
}

Scene::~Scene()
{
}
