/*
** EPITECH PROJECT, 2018
** main sokoban
** File description:
** my_sokoban project
*/

#include "include/my.h"

int write_help(void)
{
    my_putstr("USAGE\n     ./Escape\n");
    my_putstr("COMMAND\n     - press ARROWS to move, \n");
    my_putstr("     - press SPACE to retry, \n");
    my_putstr("     - press Q to leave.\n");
    return (3);
}

int choose_option(char *option)
{
    if (option && option[0] == '-' && option[1] == 'h' && option[2] == '\0')
        return (write_help());
    else
        return (open_map("map/map_bonus"));
}

int main(int ac, char **av)
{
    int state = 0;

    state = choose_option(av[1]);
    if (state == 1 || state == 2)
        my_putstr("\nGame Over !\n\n");
    if (state == 0)
        my_putstr("\nGG Well played !\n\n");
    if (state == 84)
        write(2, "\nRetry with a correct map!\n\n", 29);
    return (state);
}
