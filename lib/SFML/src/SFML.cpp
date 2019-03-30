/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#include "../include/SFML.hpp"
#include "../../../include/Error.hpp"

extern "C"
{
    std::unique_ptr<IGfx> entryPointGfx()
    {
        return std::make_unique<SFML>();
    }
}

void SFML::createWindow()
{
    _window.create(sf::VideoMode(620, 660), "Arcade");
    _window.setFramerateLimit(60);
}

int SFML::menu(std::vector<std::string> &games)
{
    _games = games;
    size_t choice = 0;

    createWindow();

    if (!_titleFont.loadFromFile("../../ressources/font/XpressiveRegular.ttf"))
        exit(84);
    if (!_textFont.loadFromFile("remachinescript.ttf"))
        exit(84);

    sf::RectangleShape menuRect(sf::Vector2f(200.f, 50.f));
    menuRect.setPosition(sf::Vector2f(210.f, 305.f));
    menuRect.setFillColor(sf::Color::Cyan);
    menuRect.setOutlineThickness(5.f);
    menuRect.setOutlineColor(sf::Color::Blue);

    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            switch (_event.type) {
                case sf::Event::Closed:
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    switch (_event.key.code) {
                        case sf::Keyboard::Return:
                            return choice;
                        case sf::Keyboard::Up:
                            menuUp(choice);
                            break;
                        case sf::Keyboard::Down:
                            menuDown(choice);
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        _window.clear(sf::Color::Black);
        _window.draw(menuRect);
        _window.display();
    }
    return 0;
}

void SFML::menuUp(size_t choice) const noexcept
{
    choice++;
    if (choice >= _games.size())
        choice = 0;
}

void SFML::menuDown(size_t choice) const noexcept
{
    if (choice == 0)
        choice = _games.size() - 1;
    else
        choice--;
}

void SFML::getEvents(IGfx::ACTION &action)
{
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                action = IGfx::ACTION::EXIT;
                break;
            default:
                break;
        }
    }
    return;
}

void SFML::clear()
{
    return;
}

void SFML::drawMap(std::shared_ptr<Map> map)
{
    (void)map;
    return;
}

void SFML::drawWall(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawPlayer(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawBody(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawPickup(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawEnemy(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawMovDoor(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawUniqueDoor(int posX, int posY)
{
    (void)posX;
    (void)posY;
    return;
}

void SFML::drawScore(int posX, int posY, int value)
{
    (void)posX;
    (void)posY;
    (void)value;
    return;
}