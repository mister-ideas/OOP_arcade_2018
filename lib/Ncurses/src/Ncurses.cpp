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

int Ncurses::menu(std::vector<std::string> &games)
{
//    WINDOW  *mainWindow = NULL;
    WINDOW  *gameWindow = NULL;
    WINDOW  *libWindow = NULL;
    WINDOW  *scoreWindow = NULL;
    WINDOW  *usernameWindow = NULL;

    std::vector<std::string> libs;

    int     offset = 1;
    int     game_offset = 1;

    initscr();
    initColors();
    keypad(stdscr, TRUE);
    cbreak();
    getScreenSize();

    // createMainWindow(lines, width, startY, startX)
//    mainWindow = createMainWindow(_screen_height, _screen_height, 0, 0);
    gameWindow = createSubWindow(stdscr, games.size() + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 1;
    libWindow = createSubWindow(stdscr, libs.size() + 2, _screen_width - 2, offset, 1);
    offset += libs.size() + 3 + 1;
    scoreWindow = createSubWindow(stdscr, games.size() + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 1;
    usernameWindow = createSubWindow(stdscr, 3, _screen_width - 2, offset, 1);

    wborder(gameWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(libWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(scoreWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(usernameWindow, 0, 0, 0, 0, 0, 0, 0, 0);

    printInsideWindow(gameWindow, 0, (_screen_width - strlen("G A M E S")) / 2, "G A M E S");
    for (auto game : games) {
        printInsideWindow(gameWindow, game_offset + 1, game.length(), game.c_str());
    }

    printInsideWindow(libWindow, 0, (_screen_width - strlen("L I B R A R I E S")) / 2, "L I B R A R I E S");
    printInsideWindow(scoreWindow, 0, (_screen_width - strlen("S C O R E S")) / 2, "S C O R E S");
    printInsideWindow(usernameWindow, 0, (_screen_width - strlen("U S E R N A M E")) / 2, "U S E R N A M E");

    refresh();
    wrefresh(gameWindow);
    wrefresh(libWindow);
    wrefresh(scoreWindow);
    wrefresh(usernameWindow);

    getch();
    endwin();
    return (0);
}

void Ncurses::initColors(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
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

WINDOW *Ncurses::createMainWindow(int posX, int posY, int width, int height)
{
    WINDOW  *window = newwin(height, width, posY, posX);

    return (window);
}

WINDOW *Ncurses::createSubWindow(WINDOW *main_window, int posX, int posY, int width, int height)
{
    WINDOW  *window = subwin(main_window, height, width, posY, posX);

    return (window);
}

void Ncurses::printInsideWindow(WINDOW *window, int posX, int posY, const char *string)
{
    mvwprintw(window, posY, posX, string);
    wrefresh(window);
}

void Ncurses::getScreenSize(void)
{
    int row = 0;
    int cols = 0;

    getmaxyx(stdscr, row, cols);
    _screen_height = row;
    _screen_width = cols;
}
