/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <vector>
#include <ncurses.h>
#include "../../include/IGfx.hpp"
#include "../../../games/include/IGame.hpp"

class Ncurses : public IGfx {
    public:
        enum GAMES {
            SELECTED,
            NOT_SELECTED
        };
        Ncurses() = default;
	~Ncurses() = default;

        // interface
        void createWindow()
        {
        };
        int menu(std::vector<std::string> &games);
        void gfxLoop(IGfx::ACTION &action)
        {
            (void) action;
        };
        void clear();
        void drawMap(std::shared_ptr<Map> map)
        {
            (void) map;
        }
        void getEvents(IGfx::ACTION &action)
        {
            (void) action;
        };

        void drawWall(int posX, int posY);          // DONE
        void drawPlayer(int posX, int posY);        // DONE
	void drawBody(int posX, int posY);          // DONE
        void drawPickup(int posX, int posY);        // DONE
        void drawEnemy(int posX, int posY);         // DONE
        void drawMovDoor(int posX, int posY);       // DONE
        void drawUniqueDoor(int posX, int posY);    // DONE
        void drawScore(int posX, int posY, int value)
        {
            (void) posX;
            (void) posY;
            (void) value;
        };

        // ncurses functions
        WINDOW  *createMainWindow(int posX, int posY, int width, int height);
        WINDOW  *createSubWindow(WINDOW *main_window, int posX, int posY, int width, int height);

        void    printInsideWindow(WINDOW *window, int posX, int posY, const char *string);
        void    getScreenSize(void);
        void    initColors(void);

    private:
        int _screen_width;
        int _screen_height;

        int _nb_games;
        int _nb_libs;

        // std::vector<int, int> _games;
        // std::vector<int, int> _libraries;

        // std::vector<std::string, int> _game_selected;
        // std::vector<std::string, int> _lib_selected;
};

#endif /* !NCURSES_HPP_ */
