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
        virtual void draw(int posX, int posY, const std::string &path, int retX = 0, int retY = 0) = 0;
};

#endif /* !IGFX_HPP_ */
