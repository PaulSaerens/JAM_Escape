/*
** EPITECH PROJECT, 2018
** fill_map
** File description:
** fill the map
*/

#include "../include/my.h"

void fill_map(char const *filepath, char **map, int line)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[BUFF_SIZE];
    int rd = read(fd, buffer, BUFF_SIZE);
    int x = 0;
    int y = 0;
    int i = 0;

    while (y != line) {
        if (i == rd) {
            i = 0;
            rd = read(fd, buffer, BUFF_SIZE);
        } else if (buffer[i] == '\n' || buffer[i] == '\0') {
            y++;
            x = 0;
            i++;
        } else {
            map[y][x] = buffer[i];
            i++;
            x++;
        }
    }
}
