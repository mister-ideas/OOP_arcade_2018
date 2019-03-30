/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** goal
*/

#ifndef GOAL_HPP_
#define GOAL_HPP_

#include <random>
#include "location.hpp"
#include "snake.hpp"

class Goal
{
public:
    Goal(const Board&, const Snake&);
    ~Goal() = default;
    void Respawn(const Board&, const Snake&);
    void Draw(Board&) const;
    const Location& GetLocation() const;
private:
    Location loc;
};

#endif /* !GOAL_HPP_ */
