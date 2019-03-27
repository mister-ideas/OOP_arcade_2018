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
        Error(const std::string &msg = "N/A");
        ~Error() = default;
        const char *what() const noexcept;

    private:
        std::string _msg;
};

#endif /* !ERROR_HPP_ */