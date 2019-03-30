/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#include "../include/Map.hpp"
#include "../../include/Error.hpp"

Map::Map(int width, int height) : _width(width), _height(height)
{
    for (int i = 0; i < height; i++) {
        std::vector<Map::ENTITY> row;
        for (int j = 0; j < width; j++)
            row.push_back(Map::ENTITY::OTHER);
        _map.push_back(row);
    }
}

Map::ENTITY Map::getEntityPos(int x, int y) const
{
    if (x <= 0 || x > _width)
        throw Error("Requested X position in map is invalid");
    if (y <= 0 || y > _height)
        throw Error("Requested Y position in map is invalid");
    return _map[y - 1][x - 1];
}

void Map::setEntityPos(int x, int y, const Map::ENTITY &type)
{
    if (x <= 0 || x > _width)
        throw Error("Requested X position in map is invalid");
    if (y <= 0 || y > _height)
        throw Error("Requested Y position in map is invalid");
    _map[y - 1][x - 1] = type;
}