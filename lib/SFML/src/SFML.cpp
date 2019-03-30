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

    if (!_titleFont.loadFromFile("lib/ressources/font/heav.ttf"))
        exit(84);
    if (!_textFont.loadFromFile("lib/ressources/font/remachinescript.ttf"))
        exit(84);
    if (!_baseFont.loadFromFile("lib/ressources/font/xpressiveregular.ttf"))
        exit(84);

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
    textGame.setPosition(sf::Vector2f(100.f, 308.f));
    textGame.setCharacterSize(30);
    textGame.setOutlineThickness(2.f);
    textGame.setOutlineColor(sf::Color::Black);

    sf::Texture backTexture;
    if (!backTexture.loadFromFile("lib/ressources/img/arcade.jpg"))
        exit(84);
    sf::Sprite backSprite(backTexture);

    sf::RectangleShape menuRect(sf::Vector2f(614.f, 50.f));
    menuRect.setPosition(sf::Vector2f(3.f, 305.f));
    menuRect.setFillColor(sf::Color::Transparent);
    menuRect.setOutlineThickness(3.f);
    menuRect.setOutlineColor(sf::Color::Cyan);

    while (_window.isOpen()) {
        _window.clear(sf::Color::Black);
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
        _window.draw(backSprite);
        _window.draw(menuRect);
        _window.draw(title);
        _window.draw(textChoose);
        textGame.setString(games[choice]);
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