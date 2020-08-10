/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all functions
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

#define BUFF_SIZE 10


typedef struct layer_t {
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f pos;
}layer_t;

typedef struct image
{
    layer_t *player;
    int rotation;
    layer_t *box;
    layer_t *death;
    layer_t *door;
    layer_t *floor;
    layer_t *wall;
    layer_t *platform;
    int win;
}image_t;

typedef struct graphic {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    char **map;
}graphic_t;

int main(int ac, char **av);
int display_map(char **map, int line, char const *filepath, int input);
void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_strline(char const *str);
int open_map(char const *filepath);
void fill_map(char const *filepath, char **map, int line);
int check_validity(char **map);

int move_player(graphic_t **en, int y, int x, image_t **image);
int move_up(int y, int x, char **map);
int move_right(int y, int x, char **map);
int move_down(int y, int x, char **map);
int move_left(int y, int x, char **map);
void push_box(int y, int x, char **map);
int check_win(char **map);
int open_road(char **map);
