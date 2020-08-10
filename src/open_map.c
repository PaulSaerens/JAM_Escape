/*
** EPITECH PROJECT, 2018
** open_map
** File description:
** open the file given as parameter
*/

#include "../include/my.h"

int nb_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[BUFF_SIZE];
    int rd = 1;
    int i = 0;
    int lines = 0;

    while (rd != 0) {
        rd = read(fd, buffer, BUFF_SIZE);
        i = 0;
        while (i < rd) {
            if (buffer[i] == '\n')
                lines++;
            i++;
        }
    }
    close(fd);
    return (lines);
}

int nb_cols(char const *filepath, int line)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[BUFF_SIZE];
    int rd = read(fd, buffer, BUFF_SIZE);
    int i;

    for (i = 0; line != 0; i++) {
        if (i == rd) {
            rd = read(fd, buffer, BUFF_SIZE);
            i = 0;
        } if (buffer[i] == '\n')
            line--;
    }
    for (line = 0; buffer[i] != '\n'; line++ && i++){
        if (i == rd) {
            rd = read(fd, buffer, BUFF_SIZE);
            i = 0;
        }
    }
    close(fd);
    return (line);
}

int open_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[BUFF_SIZE];
    int state;
    char **map;
    int y = 0;
    int line;

    if (fd == -1)
        return (84);
    line = nb_line(filepath);
    map = malloc(sizeof(char *) * line + 1);
    while (y != line) {
        map[y] = malloc(sizeof(char) * nb_cols(filepath, y));
        y++;
    }
    map[y + 1] = NULL;
    fill_map(filepath, map, line);
    close(fd);
    if (check_validity(map) != 0)
        return (84);
    state = display_map(map, line, filepath, 0);
    while (y != 0) {
        free(map[y]);
        y--;
    }
    return (state);
}
