/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** goal
*/

#include "goal.hpp"

Goal::Goal(const Board& brd, const Snake& snake)
{
    srand(time(NULL));
    Respawn(brd, snake);
}

void Goal::Respawn(const Board& brd, const Snake& snake)
{
    Location newLoc;
    do {
        newLoc.x = rand() % brd.GetWidth();
        newLoc.y = rand() % brd.GetHeight();
    } while (snake.IsInTile(newLoc));
    loc = newLoc;
}

void Goal::Draw(Board &brd) const
{
    brd.DrawCell(loc, Map::ENTITY::PICKUP);
}

const Location& Goal::GetLocation() const
{
    return loc;
}