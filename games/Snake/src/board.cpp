/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** board
*/

#include "board.hpp"
#include <SFML/Graphics.hpp>

Board::Board(std::shared_ptr<Map> map) : _map(map)
{
}

void Board::DrawCell(const Location &loc, const Map::ENTITY &entity)
{
    _map->setEntityPos(loc.x, loc.y, entity);
}

void Board::DrawLine(const Location& start, const Location& delta_loc)
{
    if (delta_loc.x != 0 && delta_loc.y != 0)
        return;
    Location tmp = start;

    for (int x = 0; x < delta_loc.x; x++) {
        tmp = start;
        tmp.x += x;
        DrawCell(tmp, Map::ENTITY::WALL);
    }
    for (int y = 0; y < delta_loc.y; y++) {
        tmp = start;
        tmp.y += y;
        DrawCell(tmp, Map::ENTITY::WALL);
    }
}

int Board::GetWidth() const {
    return _width;
}

int Board::GetHeight() const {
    return _height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
    return loc.x < _width - 1 && loc.x > 0 && loc.y < _height - 1 && loc.y > 0;
}

/*void Board::DrawGameOver() {
    //Debut du contour
    DrawLine({5, 7}, {22, 0});
    DrawLine({27, 7}, {0, 13});
    DrawLine({28, 19}, {0, 4});
    DrawLine({4, 22}, {24, 0});
    DrawLine({4, 19}, {0, 3});
    DrawLine({5, 8}, {0, 12});
    //Fin du contour
    DrawLine({7, 9}, {4, 0});
    DrawLine({7, 9}, {0, 5});
    DrawLine({8, 13}, {3, 0});
    DrawLine({10, 12}, {0, 1});
    DrawLine({9, 11}, {2, 0});
    //G finished
    DrawLine({12, 9}, {4, 0});
    DrawLine({12, 11}, {4, 0});
    DrawLine({12, 9}, {0, 5});
    DrawLine({15, 9}, {0, 5});
    //A finished
    DrawLine({17, 9}, {0, 5});
    DrawLine({21, 9}, {0, 5});
    DrawCell({20, 10});
    DrawCell({19, 11});
    DrawCell({18, 10});
    //M finished
    DrawLine({23, 9}, {3, 0});
    DrawLine({23, 11}, {2, 0});
    DrawLine({23, 13}, {3, 0});
    DrawLine({23, 9}, {0, 5});
    //E finished
    DrawLine({7, 15}, {4, 0});
    DrawLine({7, 19}, {4, 0});
    DrawLine({7, 15}, {0, 5});
    DrawLine({10, 15}, {0, 5});
    //O finished
    DrawLine({12, 15}, {0, 3});
    DrawLine({16, 15}, {0, 3});
    DrawCell({13, 18});
    DrawCell({14, 19});
    DrawCell({15, 18});
    //V finished
    DrawLine({18, 15}, {3, 0});
    DrawLine({18, 17}, {2, 0});
    DrawLine({18, 19}, {3, 0});
    DrawLine({18, 15}, {0, 5});
    //Second E finished
    DrawLine({22, 15}, {3, 0});
    DrawLine({22, 18}, {3, 0});
    DrawLine({22, 15}, {0, 5});
    DrawLine({25, 16}, {0, 2});
    DrawCell({25, 19});
    //R finished
}*/

void Board::DrawBorder()
{
    DrawLine({0, 0}, {31, 0});
    DrawLine({0, 33}, {31, 0});
    DrawLine({0, 0}, {0, 33});
    DrawLine({31, 0}, {0, 33});
}