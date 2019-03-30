/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include "../../include/IGfx.hpp"

class SFML : public IGfx {
	public:
		SFML() = default;
		~SFML() = default;

        void createWindow() final;
        int menu(std::vector<std::string> &games) final;
        void menuUp(size_t choice) const noexcept;
        void menuDown(size_t choice) const noexcept;

        void clear() final;
        void drawMap(std::shared_ptr<Map> map) final;
        void getEvents(IGfx::ACTION &action) final;

        void drawWall(int posX, int posY) final;
        void drawPlayer(int posX, int posY) final;
        void drawBody(int posX, int posY) final;
        void drawPickup(int posX, int posY) final;
        void drawEnemy(int posX, int posY) final;
        void drawMovDoor(int posX, int posY) final;
        void drawUniqueDoor(int posX, int posY) final;
        void drawScore(int posX, int posY, int value);

    private:
        std::vector<std::string> _games;
        sf::RenderWindow _window;
        sf::Event _event;

        sf::Font _titleFont;
        sf::Font _textFont;
};

#endif /* !SFML_HPP_ */