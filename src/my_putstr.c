/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Afficher une chaîne de caractère
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
