/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** location
*/

#include "../include/Location.hpp"

void Location::Add(const Location& val)
{
    x += val.x;
    y += val.y;
}

bool Location::operator==(const Location& rhs) const
{
    return x == rhs.x && y == rhs.y;
}