/*
** EPITECH PROJECT, 2018
** check_validity
** File description:
** look if the map is valid or not
*/

#include "../include/my.h"

int check_validity(char **map)
{
    int y = 0;
    int x = 0;
    int error = 0;
    int count_P = 0;

    while (map[y] != NULL) {
        while (map[y][x] != '\0') {
            if (map[y][x] == 'P')
                count_P++;
            x++;
        }
        x = 0;
        y++;
    }
    if (count_P != 1)
        error++;
    return (error);
}
