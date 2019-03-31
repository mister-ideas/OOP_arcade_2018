/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "../../games/include/Map.hpp"
#include <memory>

class IGame {
    public:
        virtual ~IGame() = default;

        virtual void generateMap() = 0;

        virtual void play() = 0;
        virtual void MoveUp() = 0;
        virtual void MoveDown() = 0;
        virtual void MoveLeft() = 0;
        virtual void MoveRight() = 0;
        virtual bool updateMap() = 0;

        virtual int getScore() = 0;
        virtual std::shared_ptr<Map> getMap() = 0;
};

#endif /* !IGAME_HPP_ */