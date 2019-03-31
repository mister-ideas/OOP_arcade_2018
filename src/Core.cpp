/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
#include <dirent.h>
#include "../include/Core.hpp"
#include "../include/Error.hpp"
#include "../include/LibLoader.hpp"

Core::Core()
{
    readDir("lib/", _gfxPaths);
    readDir("games/", _gamesPaths);
    _currentGfxPos = 0;
    _currentGamePos = 0;
    _currentGfx = nullptr;
    _currentGame = nullptr;
}

void Core::readDir(const std::string &path, std::vector<std::string> &vector)
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
    if (!vector.size())
        throw Error("There is no library in " + path + " folder");
}

void Core::loadGfx(std::string &path)
{
    while (path[0] == '.' || path[0] == '/')
        path.erase(0, 1);
    std::vector<std::string>::iterator it = std::find(_gfxPaths.begin(), _gfxPaths.end(), path);
    if (it == _gfxPaths.end())
        throw Error("Invalid path or requested graphics library not in lib folder");
    auto loader = std::make_unique<LibLoader<IGfx>>(path);
    _currentGfx = loader->getClass("entryPointGfx");
    _currentGfxPos = std::distance(_gfxPaths.begin(), it);
    loadGame(_gamesPaths[_currentGfx->menu(_gamesPaths)]);
}

void Core::loadGame(const std::string &path)
{
    std::vector<std::string>::iterator it = std::find(_gamesPaths.begin(), _gamesPaths.end(), path);
    if (it == _gamesPaths.end())
        throw Error("Requested game is not in games folder");
    auto loader = std::make_unique<LibLoader<IGame>>(path);
    _currentGame = loader->getClass("entryPointGame");
    _currentGamePos = std::distance(_gamesPaths.begin(), it);
    _currentGame->generateMap();
    start();
}

void Core::events(IGfx::ACTION &event) noexcept
{
    switch (event) {
        case IGfx::ACTION::MOVE_UP:
            _currentGame->MoveUp();
            break;
        case IGfx::ACTION::MOVE_DOWN:
            _currentGame->MoveDown();
            break;
        case IGfx::ACTION::MOVE_LEFT:
            _currentGame->MoveLeft();
            break;
        case IGfx::ACTION::MOVE_RIGHT:
            _currentGame->MoveRight();
            break;
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
            loadGame(_gamesPaths[_currentGamePos]);
            break;
        case IGfx::ACTION::MENU:
            loadGame(_gamesPaths[_currentGfx->menu(_gamesPaths)]);
            break;
        default:
            break;
    }
}

void Core::start()
{
    bool inProgress = true;
    IGfx::ACTION action = IGfx::ACTION::OTHER;

    while (inProgress) {
        _currentGfx->clear();
        _currentGfx->drawScore(100, 2, _currentGame->getScore());
        _currentGfx->drawMap(_currentGame->getMap());
        _currentGfx->getEvents(action);
        if (action == IGfx::ACTION::EXIT)
            exit(0);
        events(action);
        inProgress = _currentGame->updateMap();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    loadGame(_gamesPaths[_currentGfx->menu(_gamesPaths)]);
}

void Core::nextGfx() noexcept
{
    _currentGfx.release();
    _currentGfxPos++;
    if (_currentGfxPos > _gfxPaths.size() - 1)
        _currentGfxPos = 0;
    auto loader = std::make_unique<LibLoader<IGfx>>(_gfxPaths[_currentGfxPos]);
    _currentGfx = loader->getClass("entryPointGfx");
}

void Core::prevGfx() noexcept
{
    _currentGfx.release();
    if (_currentGfxPos == 0)
        _currentGfxPos = _gfxPaths.size() - 1;
    else
        _currentGfxPos--;
    auto loader = std::make_unique<LibLoader<IGfx>>(_gfxPaths[_currentGfxPos]);
    _currentGfx = loader->getClass("entryPointGfx");
}

void Core::nextGame() noexcept
{
    if (_currentGame)
        _currentGame.release();
    _currentGamePos++;
    if (_currentGamePos > _gamesPaths.size() - 1)
        _currentGamePos = 0;
    loadGame(_gamesPaths[_currentGamePos]);
}

void Core::prevGame() noexcept
{
    if (_currentGame)
        _currentGame.release();
    if (_currentGamePos == 0)
        _currentGamePos = _gamesPaths.size() - 1;
    else
        _currentGamePos--;
    loadGame(_gamesPaths[_currentGamePos]);
}