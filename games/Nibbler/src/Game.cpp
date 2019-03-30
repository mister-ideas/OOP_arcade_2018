/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** game
*/

#include "game.hpp"
#include <cstdlib>
#include <iostream>

Game::Game(std::Map map)
    :
{
}

void Game::gameLoop()
{
    sf::Event e;

    while (_window.isOpen()) {
        while (_window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                _window.close();
        }
        update();
        displayBoard();
    }
}

void Game::update()
{
    if (!_isGameOver) {

        }
    }
}

void Game::displayBoard()
{
    _brd.DrawBorder();
    _snake.Draw(_brd);
    _goal.Draw(_brd);
    DrawScore();
    if (_isGameOver)
        _brd.DrawGameOver();
    _window.display();
}