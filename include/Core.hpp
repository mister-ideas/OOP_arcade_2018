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
#include "../include/LibLoader.hpp"
#include "../lib/include/IGfx.hpp"
#include "../games/include/IGame.hpp"

class Core {
	public:
		Core();
		~Core() = default;

        void readDir(const std::string &path, std::vector<std::string> &vector);
        void loadGfx(std::string &path);
        void loadGame(const std::string &path);
        void nextGfx() noexcept;
        void prevGfx() noexcept;
        void nextGame() noexcept;
        void prevGame() noexcept;
        void events(IGfx::ACTION &action) noexcept;
        void start();

	private:
        std::vector<std::string> _gfxPaths;
        std::vector<std::string> _gamesPaths;
        std::unique_ptr<LibLoader<IGfx>> _gfxLoader;
        std::unique_ptr<LibLoader<IGame>> _gameLoader;
        std::unique_ptr<IGfx> _currentGfx;
        std::unique_ptr<IGame> _currentGame;
        size_t _currentGfxPos;
        size_t _currentGamePos;
};

#endif /* !CORE_HPP_ */