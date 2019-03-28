/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGfx
*/

#ifndef IGFX_HPP_
#define IGFX_HPP_

#include <string>
#include <vector>
#include <memory>
#include "../../games/include/IGame.hpp"
#include "../../include/Map.hpp"

class IGfx {
    public:
        enum ACTION {
            MOVE_UP,
            MOVE_DOWN,
            MOVE_LEFT,
            MOVE_RIGHT,
            NEXT_GFX,
            PREV_GFX,
            NEXT_GAME,
            PREV_GAME,
            RESTART,
            MENU,
            EXIT,
            OTHER
        };

        virtual ~IGfx() = default;

        virtual void createWindow() = 0;
        virtual int menu(std::vector<std::string> &games) = 0;

        virtual void gfxLoop(IGfx::ACTION &action, bool &inProgress) = 0;
        virtual void clear() = 0;
        virtual void drawMap(std::unique_ptr<Map> map) = 0;
        virtual void getEvents(IGfx::ACTION &action) = 0;

        virtual void drawWall(int posX, int posY) = 0;
        virtual void drawPlayer(int posX, int posY) = 0;
        virtual void drawBody(int posX, int posY) = 0;
        virtual void drawPickup(int posX, int posY) = 0;
        virtual void drawEnemy(int posX, int posY) = 0;
        virtual void drawMovDoor(int posX, int posY) = 0;
        virtual void drawUniqueDoor(int posX, int posY) = 0;
        virtual void drawScore(int posX, int posY, int value) = 0;

        virtual void setGame(std::shared_ptr<IGame> game) = 0;
};

#endif /* !IGFX_HPP_ */