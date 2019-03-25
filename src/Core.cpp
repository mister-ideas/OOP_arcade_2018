/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <dirent.h>
#include "Core.hpp"
#include "Error.hpp"
#include "LibLoader.hpp"

Core::Core()
{
    readDir("./lib/", _gfxPaths);
    readDir("./games/", _gamesPaths);
    _currentGfxPos = 0;
    _currentGamePos = 0;
    _currentGfx = nullptr;
    _currentGame = nullptr;
}

void Core::readDir(const std::string &path, std::vector<std::string> &vector) noexcept
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path.c_str());
    if (dir) {
        while ((entry = readdir(dir))) {
            std::string name = entry->d_name;
            size_t pos = name.find(".so");
            if (pos != std::string::npos && name.size() > 3 && pos == name.size() - 3)
                vector.push_back(path + name);
        }
    }
    closedir(dir);
}

void Core::loadGfx(const std::string &path)
{
    std::vector<std::string>::iterator it = std::find(_gfxPaths.begin(), _gfxPaths.end(), path);
    if (it == _gfxPaths.end())
        throw Error("Requested graphics library is not in lib folder");
    LibLoader<IGfx> *loader = new LibLoader<IGfx>(path);
    _currentGfxPos = std::distance(_gfxPaths.begin(), it);
    _currentGfx = loader->getClass();
    loadGame(_gamesPaths[_currentGfx->menu(_gamesPaths)]);
    start();
}

void Core::loadGame(const std::string &path)
{
    if (_currentGame)
        delete _currentGame;
    std::vector<std::string>::iterator it = std::find(_gamesPaths.begin(), _gamesPaths.end(), path);
    if (it == _gamesPaths.end())
        throw Error("Requested game is not in games folder");
    LibLoader<IGame> *loader = new LibLoader<IGame>(path);
    _currentGamePos = std::distance(_gamesPaths.begin(), it);
    _currentGame = loader->getClass();
}

void Core::events(IGfx::ACTION event) noexcept
{
    switch (event) {
        case IGfx::ACTION::NEXT_GFX:
            nextGfx();
            break;
        case IGfx::ACTION::PREV_GFX:
            prevGfx();
            break;
        case IGfx::ACTION::NEXT_GAME:
            nextGame();
            break;
        case IGfx::ACTION::PREV_GAME:
            prevGame();
            break;
        case IGfx::ACTION::RESTART:
            _currentGfx->clear();
            loadGame(_gamesPaths[_currentGamePos]);
            // load new game map
            break;
        case IGfx::ACTION::MENU:
            _currentGfx->clear();
            loadGame(_gamesPaths[_currentGfx->menu(_gamesPaths)]);
            // load new game map
            break;
        default:
            break;
    }
}

void Core::start()
{
    // core loop
}

void Core::nextGfx() noexcept
{
    delete _currentGfx;
    _currentGfxPos++;
    if (_currentGfxPos > _gfxPaths.size() - 1)
        _currentGfxPos = 0;
    LibLoader<IGfx> *loader = new LibLoader<IGfx>(_gfxPaths[_currentGfxPos]);
    _currentGfx = loader->getClass();
}

void Core::prevGfx() noexcept
{
    delete _currentGfx;
    if (_currentGfxPos == 0)
        _currentGfxPos = _gfxPaths.size() - 1;
    else
        _currentGfxPos--;
    LibLoader<IGfx> *loader = new LibLoader<IGfx>(_gfxPaths[_currentGfxPos]);
    _currentGfx = loader->getClass();
}

void Core::nextGame() noexcept
{
    if (_currentGame)
        delete _currentGame;
    _currentGamePos++;
    if (_currentGamePos > _gamesPaths.size() - 1)
        _currentGamePos = 0;
    LibLoader<IGame> *loader = new LibLoader<IGame>(_gamesPaths[_currentGamePos]);
    _currentGame = loader->getClass();
    // load new game map
}

void Core::prevGame() noexcept
{
    if (_currentGame)
        delete _currentGame;
    if (_currentGamePos == 0)
        _currentGamePos = _gamesPaths.size() - 1;
    else
        _currentGamePos--;
    LibLoader<IGame> *loader = new LibLoader<IGame>(_gamesPaths[_currentGamePos]);
    _currentGame = loader->getClass();
    // load new game map
}
