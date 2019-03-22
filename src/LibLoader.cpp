/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibLoader
*/

#include "LibLoader.hpp"
#include "Error.hpp"

template<typename T>
LibLoader<T>::LibLoader(const std::string &path)
{
    _lib = dlopen(path.c_str(), RTLD_LAZY);
    if (!_lib)
        throw Error(dlerror());
}

template<typename T>
LibLoader<T>::~LibLoader()
{
    if (dlclose(_lib) != 0)
        throw Error(dlerror());
}

template<typename T>
T *LibLoader<T>::getClass(const std::string &entryPoint) const noexcept
{
    T *(*instance)(void) = reinterpret_cast<T *(*)(void)>(dlsym(_lib, entryPoint.c_str()));
    if (!instance)
        return (nullptr);
    return instance();
}