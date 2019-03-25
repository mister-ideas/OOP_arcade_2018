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

        virtual void gfxLoop() = 0;
        virtual void createWindow() = 0;
        virtual int menu(std::vector<std::string> games) = 0;
        virtual IGfx::ACTION getEvents() = 0;
        virtual void clear() = 0;
        virtual void drawString(int posX, int posY, const char *value) = 0;
        virtual void drawSprite(int posX, int posY, const std::string &path) = 0;
        virtual void drawSpriteRet(int posX, int posY, int retX1, int retY1, int retX2, int retY2, const std::string &path) = 0;
};

#endif /* !IGFX_HPP_ */
