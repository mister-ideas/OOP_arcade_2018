/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>

class Map {
	public:
        enum ENTITY {
            WALL,
            PLAYER,
            BODY,
            PICKUP,
            ENEMY,
            MOV_DOOR,
            UNIQUE_DOOR,
            OTHER
        };

		Map(int width = 31, int height = 33);
		~Map() = default;

        Map::ENTITY getEntityPos(int x, int y) const;
        void setEntityPos(int x, int y, Map::ENTITY &type);

	private:
        std::vector<std::vector<Map::ENTITY>> _map;
        int _width;
        int _height;
};

#endif /* !MAP_HPP_ */