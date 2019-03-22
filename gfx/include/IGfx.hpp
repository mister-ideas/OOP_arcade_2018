/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGfx
*/

#ifndef IGFX_HPP_
#define IGFX_HPP_

#include <string>

class IGfx {
	public:
        // need enum for events handling
		virtual ~IGfx() = default;
        virtual void gfxLoop() = 0;
        virtual void createWindow() = 0;
        virtual void menu() = 0;
        virtual void getEvents() = 0;
        virtual void clear() = 0;
        virtual void drawChar(int posX, int posY, char value) = 0;
        virtual void drawSprite(int posX, int posY, const std::string &path) = 0;
        virtual void drawSpriteRet(int posX, int posY, int retX1, int retY1, int retX2, int retY2, const std::string &path) = 0;
};

#endif /* !IGFX_HPP_ */
