/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Error
*/

#include "../include/Error.hpp"

Error::Error(const std::string &msg) : _msg(msg)
{
}

const char *Error::what() const noexcept
{
    return _msg.c_str();
}