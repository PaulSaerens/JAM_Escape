/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Compte la taille d'une
** chaîne de caractère
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int my_strline(char const *str)
{
    int line = 0;
    int len = 0;

    while (str[len] != '\0') {
        if (str[len] == '\n')
            line++;
        len++;
    }
    return (line);
}

int my_strcolumn(char const *str)
{
    int column = 0;

    while (str[column] != '\n') {
        column++;
    }
    return (column);
}
