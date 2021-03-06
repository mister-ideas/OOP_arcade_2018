/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ncurses
*/

#include <string.h>
#include "../include/Ncurses.hpp"

extern "C"
{
    std::unique_ptr<IGfx> entryPointGfx()
    {
        return std::make_unique<Ncurses>();
    }
}

void Ncurses::createWindow()
{
    initscr();
    initColors();
    keypad(stdscr, TRUE);
    cbreak();
    getScreenSize();
}

int Ncurses::menu(std::vector<std::string> &games)
{
    WINDOW  *gameWindow = NULL;
    WINDOW  *libWindow = NULL;
    WINDOW  *scoreWindow = NULL;
    WINDOW  *usernameWindow = NULL;

    std::vector<std::string> libs;
    char    *username = NULL;

    int     offset = 1;
    int     game_offset = 2;

    createWindow();

    gameWindow = subwin(stdscr, games.size() + 2 + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 2;
    libWindow = subwin(stdscr, libs.size() + 2 + 2, _screen_width - 2, offset, 1);
    offset += libs.size() + 3 + 2;
    scoreWindow = subwin(stdscr, games.size() + 2 + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 2;
    usernameWindow = subwin(stdscr, 3 + 2, _screen_width - 2, offset, 1);

    wborder(gameWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(libWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(scoreWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(usernameWindow, 0, 0, 0, 0, 0, 0, 0, 0);

    mvwprintw(gameWindow, 0, (_screen_width - strlen("G A M E S")) / 2, "G A M E S");
    for (size_t i = 0; i < games.size(); ++i) {
        std::string game_string = games[i];
        const char  *game = game_string.c_str();

        if (i == 0) {
            wattron(gameWindow, A_STANDOUT);
            mvwprintw(gameWindow, game_offset, (_screen_width - strlen(game)) / 2, game);
            wattroff(gameWindow, A_STANDOUT);
        } else {
            mvwprintw(gameWindow, game_offset, (_screen_width - strlen(game)) / 2, game);
        }
        ++game_offset;
    }

    mvwprintw(libWindow, 0, (_screen_width - strlen("L I B R A R I E S")) / 2, "L I B R A R I E S");
    mvwprintw(scoreWindow, 0, (_screen_width - strlen("S C O R E S")) / 2, "S C O R E S");
    mvwprintw(usernameWindow, 0, (_screen_width - strlen("U S E R N A M E")) / 2, "U S E R N A M E");

    wmove(usernameWindow, 35, 2);

    refresh();
    wrefresh(gameWindow);
    wrefresh(libWindow);
    wrefresh(scoreWindow);
    wrefresh(usernameWindow);

    mvwscanw(usernameWindow, 2, 15, username);
    endwin();

    return (0);
}

void Ncurses::clear(void)
{
    erase();
}

void Ncurses::drawWall(int posX, int posY)
{
    char    wall = ACS_CKBOARD;
    mvprintw(posY, posX, &wall);
}

void Ncurses::drawPlayer(int posX, int posY)
{
    char    player = 'O';

    mvprintw(posY, posX, &player);
}

void Ncurses::drawPickup(int posX, int posY)
{
    char    pickup = ACS_DIAMOND;

    mvprintw(posY, posX, &pickup);
}

void Ncurses::drawBody(int posX, int posY)
{
    char    body = '0';

    attron(COLOR_PAIR(2));
    mvprintw(posY, posX, &body);
    attroff(COLOR_PAIR(2));
}

void Ncurses::drawEnemy(int posX, int posY)
{
    char    enemy = '#';

    mvprintw(posY, posX, &enemy);
}

void Ncurses::drawMovDoor(int posX, int posY)
{
    char    wall = ACS_CKBOARD;

    attron(COLOR_PAIR(2));
    mvprintw(posY, posX, &wall);
    attroff(COLOR_PAIR(2));
}

void Ncurses::drawUniqueDoor(int posX, int posY)
{
    char    wall = ACS_CKBOARD;

    attron(COLOR_PAIR(4));
    mvprintw(posY, posX, &wall);
    attroff(COLOR_PAIR(4));
}

/*
** Ncurses ONLY
*/

void Ncurses::getScreenSize(void)
{
    int row = 0;
    int cols = 0;

    getmaxyx(stdscr, row, cols);
    _screen_height = row;
    _screen_width = cols;
}

void Ncurses::initColors(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
}