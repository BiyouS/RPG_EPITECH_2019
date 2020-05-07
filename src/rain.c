/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rain
*/

#include "rpg.h"

static void move_dropplet(dropplet_t **rain, framebuffer_t *framebuffer)
{
    for (int i = 0; i < 100; i++) {
        if (rain[i]->started) {
            moving(rain, i);
        } else if (rain[i]->started == 0 && rand() % 100 > 95)
            rain[i]->started = 1;
        create_dropplet(framebuffer, rain, i);
    }
}

void free_rain(dropplet_t **rain, framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
    for (int i = 0; i < 100; i++)
        free(rain[i]);
    free(rain);
}

static void print_dropplet(framebuffer_t *framebuffer)
{
    for (int i = 0; i < 1280; i++)
        for (int j = 0; j < 720; j++)
            put_pixel(framebuffer, i, j, (sfColor){0, 0, 0, 0});
}

void rain(sfRenderWindow *window_str, game_t *game)
{
    print_dropplet(game->framebuffer);
    move_dropplet(game->dropplet, game->framebuffer);
    display_framebuffer(game->framebuffer, window_str);
}