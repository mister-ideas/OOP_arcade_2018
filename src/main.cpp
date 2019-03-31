/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "../include/Core.hpp"
#include "../include/Error.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw Error("USAGE: ./arcade path_to_graphics_lib_file (don't forget ./lib/ in the path!)");
        std::string arg = av[1];
        std::unique_ptr<Core> core = std::make_unique<Core>();
        core->loadGfx(arg);
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}