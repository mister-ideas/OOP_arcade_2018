/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <vector>
#include <string>
#include "../gfx/include/IGfx.hpp"
#include "../games/include/IGame.hpp"

class Core {
	public:
		Core();
		~Core() = default;

        void loadGfx(const std::string &path);
        void loadGame(const std::string &path);
        void nextGfx();
        void prevGfx();
        void nextGame();
        void prevGame();
        void events(IGfx::ACTION event) noexcept;
        void start();

	private:
        std::vector<std::string> _gfxPaths;
        std::vector<std::string> _gamesPaths;
        IGfx *_currentGfx;
        IGame *_currentGame;
        int _currentGfxPos;
        int _currentGamePos;
};

#endif /* !CORE_HPP_ */