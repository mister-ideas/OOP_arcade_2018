/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** snake
*/

#include "snake.hpp"
#include <iostream>

Snake::Snake(const Location& loc)
{
    _list[0].Init(loc);
    _list[1].Init({loc.x - 1 ,loc.y});
    _list[2].Init({loc.x - 2 ,loc.y});
    _list[3].Init({loc.x - 3 ,loc.y});
}

void Snake::MovePos(const Location& pos_loc)
{
    for (int i = _nDot - 1; i > 0; i--) {
        _list[i].Follow(_list[i - 1]);
    }
    _list[0].MoveHead(pos_loc);
}

void Snake::Grow()
{
    if (_nDot < _nDotMax) {
        _nDot++;
    }
}

void Snake::Draw(Board& brd) const
{
    for (int i = 0; i < _nDot; i++) {
        _list[i].Draw(brd);
    }
}

Location Snake::GetNextHeadLocation(const Location& loc) const
{
    Location tmpLoc(_list[0].GetLocation());
    tmpLoc.Add(loc);
    return tmpLoc;
}

Location Snake::GetQueueLocation() const
{
    Location tmpLoc(_list[_nDot - 1].GetLocation());
    return tmpLoc;
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
    for(int i = 0; i < _nDot - 1; i++)
        if (_list[i].GetLocation() == target)
            return true;
    return false;
}

bool Snake::IsInTile(const Location& target) const
{
    for(int i = 0; i < _nDot; i++)
        if (_list[i].GetLocation() == target)
            return true;
    return false;
}

void Snake::Dot::Init(const Location& loc)
{
    _loc = loc;
}

void Snake::Dot::Follow(const Dot& next)
{
    _loc = next._loc;
}

void Snake::Dot::Draw( Board& brd) const
{
    brd.DrawCell(_loc, Map::ENTITY::BODY);
}

void Snake::Dot::MoveHead(const Location& pos_loc)
{
    if (abs(pos_loc.x) + abs(pos_loc.y) > 1)
        exit;
    _loc.Add(pos_loc);
}

const Location& Snake::Dot::GetLocation() const
{
    return _loc;
}