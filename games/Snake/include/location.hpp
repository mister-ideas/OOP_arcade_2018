/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** location
*/

#ifndef LOCATION_HPP_
#define LOCATION_HPP_

struct Location
{
    void Add(const Location&);
    int x;
    int y;
    bool operator==(const Location& rhs) const;
};

#endif /* !LOCATION_HPP_ */
