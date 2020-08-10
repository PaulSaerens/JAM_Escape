/*
** EPITECH PROJECT, 2018
** display_map
** File description:
** draw the map
*/

#include "my.h"

int find_player(char **map, char choice)
{
    int x = 0;
    int y = 0;

    while (map[y][x] != 'P' && map[y][x] != 'B') {
        x++;
        if (map[y][x] == '\0') {
            x = 0;
            y++;
        }
    }
    if (choice == 'x')
        return (x);
    else if (choice == 'y')
        return (y);
}

image_t *manage_input(char const *filepath, int line, graphic_t *en, image_t *image)
{
    int input;
    int Px;
    int Py;
    sfTime timer = sfClock_getElapsedTime(en->clock);

    Px = find_player(en->map, 'x');
    Py = find_player(en->map, 'y');
    if (input == ' ')
        fill_map(filepath, en->map, line);
    else if (timer.microseconds > 75000 && en->event.type == sfEvtKeyPressed) {
        if (move_player(&en, Py, Px, &image) == 1)
            image->win = 1;
        sfClock_restart(en->clock);
    }
    return image;
}

void print_map(char **map, sfRenderWindow* window, image_t *image, sfView **cam)
{
    int y = 0;
    int x = 0;
    sfVector2f vec;

    sfRenderWindow_clear(window, sfBlack);

    for (y = 0; map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++) {
            vec.y = y * 16;
            vec.x = x * 16;
            if (map[y][x] != '.') {
                sfSprite_setPosition(image->floor->sprite, vec);
                sfSprite_setOrigin(image->floor->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->floor->sprite, NULL);
            }
            if (map[y][x] == '!') {
                sfSprite_setPosition(image->death->sprite, vec);
                sfSprite_setOrigin(image->death->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->death->sprite, NULL);
            }
            if (map[y][x] == 'X' || map[y][x] == 'V') {
                sfSprite_setPosition(image->box->sprite, vec);
                sfSprite_setOrigin(image->box->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->box->sprite, NULL);
            }
            if (map[y][x] == '|') {
                sfSprite_setPosition(image->door->sprite, vec);
                sfSprite_setOrigin(image->door->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->door->sprite, NULL);
            }
            if (map[y][x] == 'O') {
                sfSprite_setPosition(image->platform->sprite, vec);
                sfSprite_setOrigin(image->platform->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->platform->sprite, NULL);
            }
            if (map[y][x] == 'P' || map[y][x] == 'B') {
                sfSprite_setPosition(image->player->sprite, vec);
                sfSprite_setOrigin(image->player->sprite, (sfVector2f){8, 8});
                sfSprite_setRotation(image->player->sprite, 90 * image->rotation);
                sfRenderWindow_drawSprite(window, image->player->sprite, NULL);
                sfView_setCenter(*cam, vec);
            }
            if (map[y][x] == '#') {
                sfSprite_setPosition(image->wall->sprite, vec);
                sfSprite_setOrigin(image->wall->sprite, (sfVector2f){8, 8});
                sfRenderWindow_drawSprite(window, image->wall->sprite, NULL);
            }
        }
    }
    sfRenderWindow_setView(window, *cam);
    sfRenderWindow_display(window);
}

// map = Carte de jeu
// line = nb de ligne
// input = 0 au départ

layer_t *create_sprite(char const *filename)
{
    layer_t *layer = malloc(sizeof(layer_t));

    layer->texture = sfTexture_createFromFile(filename, NULL);
    if (!layer->texture)
        return NULL;
    layer->sprite = sfSprite_create();
    sfSprite_setTexture(layer->sprite, layer->texture, sfTrue);
    return layer;
}

image_t *create_image(image_t *image)
{
    image = malloc(sizeof(image_t));
    image->player = create_sprite("ressources/player.png");
    image->box = create_sprite("ressources/box.jpeg");
    image->door = create_sprite("ressources/rock.png");
    image->floor = create_sprite("ressources/floor.jpg");
    image->wall = create_sprite("ressources/wall.jpg");
    image->platform = create_sprite("ressources/platform.png");
    image->death = create_sprite("ressources/spike.png");
    return image;
}

void put_spikes_on_map(graphic_t *en)
{
    int i, j = 0;
    int pointY = 0;
    int pointX = 0;
    int spike = 0;

    for (i = 0 ; en->map[i]; i += 1) {
        for (j = 0 ; en->map[i][j] ; j += 1)
            if (en->map[i][j] == '!') {
                en->map[i][j] = ' ';
            }
    }
    while (spike < 5) {
        while (en->map[pointY][pointX] != ' ') {
            pointY = rand() % i;
            pointX = rand() % j;
        }
        spike += 1;
        en->map[pointY][pointX] = '!';
    }
}

int display_map(char **map, int line, char const *filepath, int input)
{
    graphic_t en;
    image_t *image = create_image(image);
    sfVideoMode mode = {1920, 1080, 32};
    sfView *camera = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfClock *spikeClock = sfClock_create();
    sfClock *gameClock = sfClock_create();

    image->win = 2;
    en.window = sfRenderWindow_create(mode, "Escape", sfResize | sfClose, NULL);
    en.clock = sfClock_create();
    en.map = map;

    sfView_setViewport(camera, (sfFloatRect){0, 0, 1, 1});
    sfView_zoom(camera, 0.25);

    while (image->win != 0 && image->win != 1 && sfRenderWindow_isOpen(en.window)) {
        if (sfClock_getElapsedTime(gameClock).microseconds >= 5000) {
            if (sfClock_getElapsedTime(spikeClock).microseconds >= 2500000) {
                put_spikes_on_map(&en);
                sfClock_restart(spikeClock);
            }
            sfRenderWindow_pollEvent(en.window, &en.event);
            if (en.event.type == sfEvtClosed || en.event.key.code == sfKeyQ)
                sfRenderWindow_close(en.window);
            print_map(en.map, en.window, image, &camera);
            image->win = check_win(en.map);
            image = manage_input(filepath, line, &en, image);
            open_road(en.map);
            sfClock_restart(gameClock);
        }
    }
    return image->win;
}
