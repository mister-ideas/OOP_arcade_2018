/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKEGAME_HPP_
#define SNAKEGAME_HPP_

#include "IGame.hpp"
#include "Map.hpp"
#include "game.hpp"
#include <memory>

class SnakeGame : public IGame {
public:
    SnakeGame();
    ~SnakeGame() = default;
    void generateMap();

    void play();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    bool updateMap();

    int getScore();
    std::shared_ptr<Map> getMap();

private:
    std::shared_ptr<Map> _map;
    Board _brd;
    Snake _snake;
    Goal _goal;
    Location _delta_loc;
    bool _isGameOver;
    int _intScore;
}

#endif /* !SNAKEGAME_HPP_ */
