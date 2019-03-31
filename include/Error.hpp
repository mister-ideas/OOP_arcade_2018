/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

class Error : public std::exception {
    public:
        explicit Error(const std::string &msg) : _msg(std::move(msg))
        {
        }

        ~Error() = default;

        const char* what() const noexcept override
        {
            return _msg.c_str();
        }

    private:
        std::string _msg;
};

#endif /* !ERROR_HPP_ */