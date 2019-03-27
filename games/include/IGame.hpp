/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

class IGame {
    public:
        enum ENTITY {
            WALL,
            PLAYER,
            PICKUP,
            ENEMY,
            MOV_DOOR,
            UNIQUE_DOOR,
            OTHER
        };

        virtual ~IGame() = default;

        virtual void generateMap() = 0;

        virtual void play() = 0;
        virtual void updateMap() = 0;
        virtual void displayScore(int posX, int posY, int value) = 0;

        virtual std::unique_ptr<Map> getMap() = 0;
};

#endif /* !IGAME_HPP_ */