/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#include <iostream>
#include "../include/SFML.hpp"
#include "../../../include/Error.hpp"

extern "C"
{
    std::unique_ptr<IGfx> entryPointGfx()
    {
        return std::make_unique<SFML>();
    }
}

SFML::SFML()
{
    createWindow();

    if (!_titleFont.loadFromFile("lib/ressources/font/heav.ttf"))
        exit(84);
    if (!_textFont.loadFromFile("lib/ressources/font/remachinescript.ttf"))
        exit(84);
    if (!_baseFont.loadFromFile("lib/ressources/font/xpressiveregular.ttf"))
        exit(84);
}

void SFML::createWindow()
{
    _window.create(sf::VideoMode(620, 700), "Arcade");
    _window.setFramerateLimit(60);
}

int SFML::menu(std::vector<std::string> &games)
{
    _games = games;
    size_t choice = 0;

    sf::Texture backTexture;
    if (!backTexture.loadFromFile("lib/ressources/img/arcade.jpg"))
        exit(84);
    sf::Sprite backSprite(backTexture);

    sf::Text title;
    title.setFont(_titleFont);
    title.setString("Arcade");
    title.setPosition(sf::Vector2f(180.f, 30.f));
    title.setCharacterSize(80);
    title.setFillColor(sf::Color::Blue);
    title.setOutlineThickness(2.f);
    title.setOutlineColor(sf::Color::White);

    sf::Text textChoose;
    textChoose.setFont(_textFont);
    textChoose.setString("Choose your game!");
    textChoose.setPosition(sf::Vector2f(175.f, 120.f));
    textChoose.setCharacterSize(60);
    textChoose.setOutlineThickness(2.f);
    textChoose.setOutlineColor(sf::Color::Black);

    sf::Text textGame;
    textGame.setFont(_baseFont);
    textGame.setPosition(sf::Vector2f(100.f, 330.f));
    textGame.setCharacterSize(30);
    textGame.setOutlineThickness(2.f);
    textGame.setOutlineColor(sf::Color::Black);

    sf::RectangleShape menuRect(sf::Vector2f(620.f, 50.f));
    menuRect.setPosition(sf::Vector2f(0.f, 330.f));
    menuRect.setFillColor(sf::Color::Transparent);
    menuRect.setOutlineThickness(-3.f);
    menuRect.setOutlineColor(sf::Color::Cyan);

    while (_window.isOpen()) {
        clear();
        while (_window.pollEvent(_event)) {
            switch (_event.type) {
                case sf::Event::Closed:
                    exit(0);
                case sf::Event::KeyPressed:
                    switch (_event.key.code) {
                        case sf::Keyboard::Escape:
                            exit(0);
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
        _window.draw(backSprite);
        _window.draw(menuRect);
        _window.draw(title);
        _window.draw(textChoose);
        textGame.setString(_games[choice]);
        _window.draw(textGame);

        _window.display();
    }
    return 0;
}

void SFML::menuUp(size_t &choice) const noexcept
{
    choice++;
    if (choice >= _games.size())
        choice = 0;
}

void SFML::menuDown(size_t &choice) const noexcept
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
            case sf::Event::KeyPressed:
                switch (_event.key.code) {
                    case sf::Keyboard::Escape:
                        action = IGfx::ACTION::EXIT;
                        break;
                    case sf::Keyboard::Z:
                        action = IGfx::ACTION::MOVE_UP;
                        break;
                    case sf::Keyboard::S:
                        action = IGfx::ACTION::MOVE_DOWN;
                        break;
                    case sf::Keyboard::Q:
                        action = IGfx::ACTION::MOVE_LEFT;
                        break;
                    case sf::Keyboard::D:
                        action = IGfx::ACTION::MOVE_RIGHT;
                        break;
                    case sf::Keyboard::Up:
                        action = IGfx::ACTION::NEXT_GAME;
                        break;
                    case sf::Keyboard::Down:
                        action = IGfx::ACTION::PREV_GAME;
                        break;
                    case sf::Keyboard::Left:
                        action = IGfx::ACTION::PREV_GFX;
                        break;
                    case sf::Keyboard::Right:
                        action = IGfx::ACTION::NEXT_GFX;
                        break;
                    case sf::Keyboard::M:
                        action = IGfx::ACTION::MENU;
                        break;
                    case sf::Keyboard::R:
                        action = IGfx::ACTION::RESTART;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return;
}

void SFML::clear()
{
    _window.clear(sf::Color::Black);
}

void SFML::drawMap(std::shared_ptr<Map> map)
{
    try {
        for (int i = 0; i < map->getHeight(); i++) {
            for (int j = 0; j < map->getWidth(); j++) {
                switch (map->getEntityPos(j + 1, i + 1)) {
                    case Map::ENTITY::WALL:
                        drawWall(j, i);
                        break;
                    case Map::ENTITY::PLAYER:
                        drawPlayer(j, i);
                        break;
                    case Map::ENTITY::BODY:
                        drawBody(j, i);
                        break;
                    case Map::ENTITY::PICKUP:
                        drawPickup(j, i);
                        break;
                    case Map::ENTITY::ENEMY:
                        drawEnemy(j, i);
                        break;
                    case Map::ENTITY::MOV_DOOR:
                        drawMovDoor(j, i);
                        break;
                    case Map::ENTITY::UNIQUE_DOOR:
                        drawUniqueDoor(j, i);
                        break;
                    default:
                        break;
                }
            }
        }
        _window.display();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

void SFML::drawWall(int posX, int posY)
{
    sf::RectangleShape wall(sf::Vector2f(20.f, 20.f));
    wall.setPosition(sf::Vector2f((float)posX * 20, (float)(posY * 20) + 40));
    wall.setFillColor(sf::Color::Blue);
    _window.draw(wall);
}

void SFML::drawPlayer(int posX, int posY)
{
    sf::RectangleShape player(sf::Vector2f(20.f, 20.f));
    player.setPosition(sf::Vector2f((float)posX * 20, (float)(posY * 20) + 40));
    player.setFillColor(sf::Color::Cyan);
    _window.draw(player);
}

void SFML::drawBody(int posX, int posY)
{
    sf::RectangleShape body(sf::Vector2f(20.f, 20.f));
    body.setPosition(sf::Vector2f((float)posX * 20, (float)(posY * 20) + 40));
    body.setFillColor(sf::Color::Magenta);
    _window.draw(body);
}

void SFML::drawPickup(int posX, int posY)
{
    sf::CircleShape pickup(2.f);
    pickup.setPosition(sf::Vector2f((float)(posX * 20) + 8, (float)(posY * 20) + 48));
    pickup.setFillColor(sf::Color::Yellow);
    _window.draw(pickup);
    return;
}

void SFML::drawEnemy(int posX, int posY)
{
    sf::CircleShape enemy(5.f);
    enemy.setPosition(sf::Vector2f((float)(posX * 20) + 5, (float)(posY * 20) + 45));
    enemy.setFillColor(sf::Color::Red);
    _window.draw(enemy);
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
    sf::Text textScore;
    textScore.setFont(_baseFont);
    textScore.setPosition(sf::Vector2f((float)posX, (float)posY));
    textScore.setString("Score: " + std::to_string(value));
    textScore.setCharacterSize(30);
    _window.draw(textScore);
    return;
}