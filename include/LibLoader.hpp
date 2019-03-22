/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include <string>
#include <dlfcn.h>

template <typename T>
class LibLoader {
	public:
		LibLoader(const std::string &path);
		~LibLoader();

        T *getClass(const std::string &entryPoint) const noexcept;

	private:
        void *_lib;
};

#endif /* !LIBLOADER_HPP_ */
