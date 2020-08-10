/*
** EPITECH PROJECT, 2018
** move_direction
** File description:
** manage player's directions
*/

#include "../include/my.h"

int move_up(int y, int x, char **map)
{
    int circle = 0;

    if (map[y][x] == 'B')
        circle = 1;
    if ((map[y - 1][x] == '!') || (map[y - 1][x] == 'X' && map[y - 2][x] == '!'))
        return 1;
    if ((map[y-1][x] == 'X' || map[y-1][x] == 'V') && map[y-2][x] != '#' &&
        map[y-2][x] != 'X' && map[y-2][x] != 'V' && map[y-2][x] != '|') {
        if (map[y-1][x] == 'V')
            map[y-1][x] = 'O';
        push_box(y-2, x, map);
    }
    else if ((map[y-1][x] == 'X' || map[y-1][x] == 'V') && (map[y-2][x] == '|'
            || map[y-2][x] == '#' || map[y-2][x] == 'X' || map[y-2][x] == 'V'))
        return 0;
    if (map[y-1][x] == 'O')
        map[y-1][x] = 'B';
    else
        map[y-1][x] = 'P';
    map[y][x] = ' ';
    if (circle == 1)
        map[y][x] = 'O';
    return 0;
}

int move_right(int y, int x, char **map)
{
    int circle = 0;

    if (map[y][x] == 'B')
        circle = 1;
    if ((map[y][x + 1] == '!') || (map[y][x + 1] == 'X' && map[y][x + 2] == '!'))
        return 1;
    if ((map[y][x+1] == 'X' || map[y][x+1] == 'V') && map[y][x+2] != '#' &&
        map[y][x+2] != 'X' && map[y][x+2] != 'V' && map[y][x+2] != '|') {
        if (map[y][x+1] == 'V')
            map[y][x+1] = 'O';
        push_box(y, x+2, map);
    }
    else if ((map[y][x+1] == 'X' || map[y][x+1] == 'V') && (map[y][x+2] == '|'
            || map[y][x+2] == '#' || map[y][x+2] == 'X' || map[y][x+2] == 'V'))
        return 0;
    if (map[y][x+1] == 'O')
        map[y][x+1] = 'B';
    else
        map[y][x+1] = 'P';
    map[y][x] = ' ';
    if (circle == 1)
        map[y][x] = 'O';
    return 0;
}

int move_down(int y, int x, char **map)
{
    int circle = 0;
    if (map[y][x] == 'B')
        circle = 1;
    if ((map[y + 1][x] == '!') || (map[y + 1][x] == 'X' && map[y + 2][x] == '!'))
        return 1;
    if ((map[y+1][x] == 'X' || map[y+1][x] == 'V') && map[y+2][x] != '#' &&
        map[y+2][x] != 'X' && map[y+2][x] != 'V' && map[y+2][x] != '|') {
        if (map[y+1][x] == 'V')
            map[y+1][x] = 'O';
        push_box(y+2, x, map);
    }
    else if ((map[y+1][x] == 'X' || map[y+1][x] == 'V') && (map[y+2][x] == '|'
            || map[y+2][x] == '#' || map[y+2][x] == 'X' || map[y+2][x] == 'V'))
        return 0;
    if (map[y+1][x] == 'O')
        map[y+1][x] = 'B';
    else
        map[y+1][x] = 'P';
    map[y][x] = ' ';
    if (circle == 1)
        map[y][x] = 'O';
    return 0;
}

int move_left(int y, int x, char **map)
{
    int circle = 0;

    if (map[y][x] == 'B')
        circle = 1;
    if ((map[y][x - 1] == '!') || (map[y][x - 1] == 'X' && map[y][x - 1] == '!'))
        return 1;
    if ((map[y][x-1] == 'X' || map[y][x-1] == 'V') && map[y][x-2] != '#' &&
        map[y][x-2] != 'X' && map[y][x-2] != 'V' && map[y][x-2] != '|') {
        if (map[y][x-1] == 'V')
            map[y][x-1] = 'O';
        push_box(y, x-2, map);
    }
    else if ((map[y][x-1] == 'X' || map[y][x-1] == 'V') && (map[y][x-2] == '|'
            || map[y][x-2] == '#' || map[y][x-2] == 'X' || map[y][x-2] == 'V'))
        return 0;
    if (map[y][x-1] == 'O')
        map[y][x-1] = 'B';
    else
        map[y][x-1] = 'P';
    map[y][x] = ' ';
    if (circle == 1)
        map[y][x] = 'O';
    return 0;
}
