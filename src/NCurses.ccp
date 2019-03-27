/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ncurses
*/

#include "./gfx/include/Ncurses.hpp"
#include <string.h>

NCurses::NCurses(void)
{

}

int NCurses::menu(std::vector<std::string> games)
{
    WINDOW  *mainWindow = NULL;
    WINDOW  *gameWindow = NULL;
    WINDOW  *libWindow = NULL;
    WINDOW  *scoreWindow = NULL;
    WINDOW  *usernameWindow = NULL;

    std::vector<std::string> libs;

    int     offset = 1;
    int     game_offset = 1;

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    getScreenSize();

    mainWindow = createMainWindow(_screen_height, _screen_height, 0, 0);
    // createMainWindow(lines, width, startY, startX)
    gameWindow = createSubWindow(mainWindow, games.size() + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 1;
    libWindow = createSubWindow(mainWindow, libs.size() + 2, _screen_width - 2, offset, 1);
    offset += libs.size() + 3 + 1;
    scoreWindow = createSubWindow(mainWindow, games.size() + 2, _screen_width - 2, offset, 1);
    offset += games.size() + 3 + 1;
    usernameWindow = createSubWindow(mainWindow, 3, _screen_width - 2, offset, 1);

    wborder(gameWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(libWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(scoreWindow, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(usernameWindow, 0, 0, 0, 0, 0, 0, 0, 0);

    printInsideWindow(gameWindow, 0, (_screen_width - strlen("G A M E S")) / 2, "G A M E S");
    for (auto game : games) {
        printInsideWindow(gameWindow, game_offset + 1, game.length, game.c_str());
    }

    printInsideWindow(libWindow, 0, (_screen_width - strlen("L I B R A R I E S")) / 2, "L I B R A R I E S");
    printInsideWindow(scoreWindow, 0, (_screen_width - strlen("S C O R E S")) / 2, "S C O R E S");
    printInsideWindow(usernameWindow, 0, (_screen_width - strlen("U S E R N A M E")) / 2, "U S E R N A M E");

    refresh();

    getch();
    endwin();
}

void NCurses::clear(void)
{
    erase();
}


void NCurses::drawWall(int posX, int posY)
{
    char    wall = ACS_CKBOARD;

    mvprintw(posY, posX, &wall);
}

void NCurses::drawPlayer(int posX, int posY)
{
    char    player = 'O';

    mvprintw(posY, posX, &player);
}

void NCurses::drawPickup(int posX, int posY)
{
    char    pickup = ACS_DIAMOND;

    mvprintw(posY, posX, &pickup);
}

void NCurses::drawEnemy(int posX, int posY)
{
    char    enemy = '#';

    mvprintw(posY, posX, &enemy);
}

/*
** NCURSES ONLY
*/

WINDOW *NCurses::createMainWindow(int posX, int posY, int width, int height)
{
    WINDOW  *window = newwin(height, width, posY, posX);

    return (window);
}

WINDOW *NCurses::createSubWindow(WINDOW *main_window, int posX, int posY, int width, int height)
{
    WINDOW  *window = subwin(main_window, height, width, posY, posX);

    return (window);
}

void NCurses::printInsideWindow(WINDOW *window, int posX, int posY, const char *string)
{
    mvwprintw(window, posY, posX, string);
    wrefresh(window);
}

void NCurses::getScreenSize(void)
{
    int row = 0;
    int cols = 0;

    getmaxyx(stdscr, row, cols);
    _screen_height = row;
    _screen_width = cols;
}

// NCurses::~NCurses(void)
// {
// 	endwin();
// }