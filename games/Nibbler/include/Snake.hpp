/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../include/Location.hpp"
#include "../include/Board.hpp"

class Snake
{
public:
    Snake(const Location&);
    ~Snake() = default;
    void MovePos(const Location&);
    void Grow();
    void Draw(Board &brd) const;
    Location GetNextHeadLocation(const Location&) const;
    Location GetTailLocation() const;
    bool IsInTileExceptEnd(const Location&) const;
    bool IsInTile(const Location&) const;
private:
    class Dot
    {
    public:
        void Init(const Location&);
        void Follow(const Dot&);
        void MoveHead(const Location&);
        void Draw(Board& brd, const Map::ENTITY&) const;
        const Location& GetLocation() const;
    private:
        Location _loc;
    };

    static constexpr int _nDotMax = 100;
    Dot _list[_nDotMax];
    int _nDot = 4;
};

#endif /* !SNAKE_HPP_ */