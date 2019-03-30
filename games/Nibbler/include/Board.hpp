/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** board
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "../include/Location.hpp"
#include "../../include/Map.hpp"
#include <memory>

class Board {
public:
    Board(std::shared_ptr<Map> = nullptr);
    ~Board() = default;
    void DrawCell(const Location&, const Map::ENTITY&);
    int GetWidth() const;
    int GetHeight() const;
    bool IsInsideBoard(const Location&) const;
    //void DrawGameOver();
    void DrawLine(const Location&, const Location&);
    void DrawBorder();

private:
    std::shared_ptr<Map> _map;
    static constexpr int _cell_size = 20;
    static constexpr int _width = 31;
    static constexpr int _height = 33;
    static constexpr int _off_x = 20 * 32;
    static constexpr int _off_y = 20 * 10;
};

#endif /* !BOARD_HPP_ */
