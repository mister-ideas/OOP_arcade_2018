/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include <iostream>
#include "../include/SnakeGame.hpp"

extern "C"
{
    std::unique_ptr<IGame> entryPointGame()
    {
        return std::make_unique<SnakeGame>();
    }
}

SnakeGame::SnakeGame()
    : _brd()
    , _snake({ 15, 15 })
    , _goal(_brd, _snake)
    , _delta_loc({ 1, 0 })
    , _isGameOver(false)
    , _intScore(0)
{
    _map = std::make_shared<Map>();
    _brd = Board(_map);
    _goal = Goal(_brd, _snake);
}

void SnakeGame::generateMap()
{
    _brd.DrawBorder();
    _snake.Draw(_brd);
    _goal.Draw(_brd);
}

void SnakeGame::play()
{
    return;
}

void SnakeGame::MoveUp()
{
    if (_delta_loc.y != 1)
        _delta_loc = { 0, -1 };
}

void SnakeGame::MoveDown()
{
    if (_delta_loc.y != -1)
        _delta_loc = { 0, 1 };
}

void SnakeGame::MoveLeft()
{
    if (_delta_loc.x != 1)
        _delta_loc = { -1, 0 };
}

void SnakeGame::MoveRight()
{
    if (_delta_loc.x != -1)
        _delta_loc = { 1, 0 };
}

bool SnakeGame::updateMap()
{
    try {
        const Location next = _snake.GetNextHeadLocation(_delta_loc);

        if (!_brd.IsInsideBoard(next)
            || _snake.IsInTileExceptEnd(next) || _isGameOver == true)
            return false;
        else {
            bool eating = next == _goal.GetLocation();
            if (eating) {
                _snake.Grow();
                _intScore += 100;
            }
            _snake.MovePos(_delta_loc);
            if (eating) {
                _goal.Respawn(_brd, _snake);
                _goal.Draw(_brd);
            }
        }
        for (int i = 1; i < _map->getHeight(); i++) {
            for (int j = 1; j < _map->getWidth(); j++)
                _map->setEntityPos(j, i, Map::ENTITY::OTHER);
        }
        _brd.DrawBorder();
        _snake.Draw(_brd);
        _goal.Draw(_brd);
        return true;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

int SnakeGame::getScore()
{
    return _intScore;
}

std::shared_ptr<Map> SnakeGame::getMap()
{
    return _map;
}