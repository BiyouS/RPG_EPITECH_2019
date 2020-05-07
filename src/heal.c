/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal
*/

#include "rpg.h"

static void move_dropplet(dropplet_t **heal, framebuffer_t *framebuffer, \
sfIntRect extract)
{
    for (int i = 0; i < 500; i++) {
        if (heal[i]->started) {
            moving_heal(heal, i);
        } else if (heal[i]->started == 0 && rand() % 100 > 95)
            heal[i]->started = 1;
        create_dropplet_heal(framebuffer, heal, i, extract);
    }
}

void free_heal(dropplet_t **heal, framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
    for (int i = 0; i < 500; i++)
        free(heal[i]);
    free(heal);
}

static void print_dropplet(framebuffer_t *framebuffer, sfIntRect extract)
{
    for (int i = extract.left; i > 0 \
&& i < extract.width + extract.left + 10 && i < 1280; i++)
        for (int j = extract.top; j > 0 \
&& j < extract.top + extract.height + 10 && j < 720; j++)
            put_pixel(framebuffer, i, j, (sfColor){0, 0, 0, 0});
}

void heal(sfRenderWindow *window_str, game_t *game, sfIntRect extract)
{
    print_dropplet(game->framebuffer, extract);
    move_dropplet(game->dropplet_heal, game->framebuffer, extract);
    display_framebuffer(game->framebuffer, window_str);
}