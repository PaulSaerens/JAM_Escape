/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** move the player with arrows
*/

#include "../include/my.h"

void push_box(int y, int x, char **map)
{
    if (map[y][x] == 'O')
            map[y][x] = 'V';
    else
        map[y][x] = 'X';
}

int move_player(graphic_t **en, int y, int x, image_t **image)
{
    int input = (*en)->event.key.code;
    if (input == 71) {
        (*image)->rotation = 1;
        if ((*en)->map[y][x - 1] != '#' && (*en)->map[y][x - 1] != '|')
            return move_left(y, x, (*en)->map);
    }
    if (input == 72) {
        (*image)->rotation = 3;
        if ((*en)->map[y][x + 1] != '#' && (*en)->map[y][x + 1] != '|')
            return move_right(y, x, (*en)->map);
    }
    if (input == 73) {
        (*image)->rotation = 2;
        if ((*en)->map[y - 1][x] != '#' && (*en)->map[y - 1][x] != '|')
            return move_up(y, x, (*en)->map);
    }
    if (input == 74) {
        (*image)->rotation = 0;
        if ((*en)->map[y + 1][x] != '#' && (*en)->map[y + 1][x] != '|')
            return move_down(y, x, (*en)->map);
    }
}
