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
#include "../lib/include/IGfx.hpp"
#include "../games/include/IGame.hpp"

class Core {
	public:
		Core();
		~Core() = default;

        void readDir(const std::string &path, std::vector<std::string> &vector) noexcept;
        void loadGfx(const std::string &path);
        void loadGame(const std::string &path);
        void nextGfx() noexcept;
        void prevGfx() noexcept;
        void nextGame() noexcept;
        void prevGame() noexcept;
        void events(IGfx::ACTION event) noexcept;
        void start();

	private:
        std::vector<std::string> _gfxPaths;
        std::vector<std::string> _gamesPaths;
        IGfx *_currentGfx;
        IGame *_currentGame;
        size_t _currentGfxPos;
        size_t _currentGamePos;
};

#endif /* !CORE_HPP_ */