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
		LibLoader(const std::string &path) noexcept(false) {
            _lib = dlopen(path.c_str(), RTLD_NOW);
            if (!_lib)
                throw Error(dlerror());
        };

		~LibLoader() noexcept(false) {
            if (dlclose(_lib) != 0)
                throw Error(dlerror());
        };

        std::unique_ptr<T> getClass(const std::string &entryPoint) const {
            std::unique_ptr<T>(*instance)(void) = reinterpret_cast<std::unique_ptr<T>(*)(void)>(dlsym(_lib, entryPoint.c_str()));
            if (!instance)
                throw Error(dlerror());
            return instance();
        };

	private:
        void *_lib;
};

#endif /* !LIBLOADER_HPP_ */