/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <vector>
#include "IGfx.hpp"

class NCurses : public IGfx {
    public:
        enum GAMES {
            SELECTED,
            NOT_SELECTED
        };
        NCurses();

        // interface
        void createWindow()
        {
        };
        int menu(std::vector<std::string> games);
        void gfxLoop(IGfx::ACTION &action)
        {
        };
        void clear();
        void drawMap(std::unique_ptr<Map> map);
        void getEvents(IGfx::ACTION &action)
        {
        };

        void drawWall(int posX, int posY);          // DONE
        void drawPlayer(int posX, int posY);        //DONE
        void drawPickup(int posX, int posY);        // DONE
        void drawEnemy(int posX, int posY);         // DONE
        void drawMovDoor(int posX, int posY)
        {
        };
        void drawUniqueDoor(int posX, int posY)
        {
        };
        void setGame(std::shared_ptr<IGame> game)
        {
        };

        // ncurses functions
        WINDOW  *createMainWindow(int posX, int posY, int width, int height);
        WINDOW  *createSubWindow(WINDOW *main_window, int posX, int posY, int width, int height);

        void    printInsideWindow(WINDOW *window, int posX, int posY, const char *string);
        void    getScreenSize(void);

    private:
        int _screen_width;
        int _screen_height;

        int _nb_games;
        int _nb_libs;

        std::vector<int, int> _games;
        std::vector<int, int> _libraries;

        std::vector<std::string, int> _game_selected;
        std::vector<std::string, int> _lib_selected;
};

#endif /* !NCURSES_HPP_ */