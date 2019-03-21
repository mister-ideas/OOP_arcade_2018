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
		virtual ~IGame() = default;
        virtual void gameLoop() = 0;
        virtual void generateMap() = 0;
        virtual void displayScore(int posX, int posY, int value) = 0;
};

#endif /* !IGAME_HPP_ */
