/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include <iostream>
#include "../include/Core.hpp"
#include "../include/Error.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw Error("Bad number of arguments");
        std::string arg = av[1];
        Core *core = new Core();
        core->loadGfx(arg);
        return 0;
    } catch (Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}