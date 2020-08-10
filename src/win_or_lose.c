/*
** EPITECH PROJECT, 2018
** win or lose condiotions
** File description:
** check win/lose & open the road ('|').
*/

#include "../include/my.h"

int open_road(char **map)
{
    int y;
    int x;
    int door = 0;
    int valid = 0;

    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == 'O' || map[y][x] == 'B')
                valid++;
            if (map[y][x] == '|')
                door++;
        }
    }
    y = 0;
    if (valid == door && door != 0) {
        for (x = 0; map[y][x] != '|'; x++) {
            if (map[y][x] == '\0') {
                x = 0;
                y++;
            }
        }
        map[y][x] = ' ';
    }
    return (0);
}

int check_lose(char **map, int x, int y)
{
    if ((map[y+1][x] == '#' && map[y][x+1] == '#') ||
        (map[y+1][x] == '#' && map[y][x-1] == '#') ||
        (map[y-1][x] == '#' && map[y][x+1] == '#') ||
        (map[y-1][x] == '#' && map[y][x-1] == '#'))
        return (1);
    return (0);
}

int check_win(char **map)
{
    int x;
    int y;
    int empty_place = 0;
    int fail = 0;
    int box = 0;

    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            if (map[y][x] == 'O' || map[y][x] == 'B')
                empty_place++;
            if (map[y][x] == 'X') {
                box++;
                fail = fail + 1 - check_lose(map, x, y);
            }
        }
    } if (empty_place == 0 || box == 0)
        return (0);
    else if (fail == 0)
        return (1);
    return (2);
}
