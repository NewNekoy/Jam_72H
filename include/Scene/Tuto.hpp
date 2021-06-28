/*
** EPITECH PROJECT, 2021
** JAM
** File description:
** Tuto
*/

#ifndef TUTO_HPP_
#define TUTO_HPP_

#include "../Scene.hpp"
#include "../Button.hpp"

class Tuto : public Scene
{
    public:
        Tuto();
        ~Tuto();

        void run(Core *core);
        const int getId();

    protected:
    private:
        int _id;
};

#endif /* !TUTO_HPP_ */
