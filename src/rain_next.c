/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rain_next
*/

#include "rpg.h"

dropplet_t **init_rain(void)
{
    dropplet_t **rain = malloc(sizeof(dropplet_t *) * (99 + 1));

    for (int i = 0; i < 100; i++) {
        rain[i] = malloc(sizeof(dropplet_t));
        rain[i]->top = -10;
        rain[i]->bottom = 0;
        rain[i]->x = rand() % 1280;
        rain[i]->started = 0;
        rain[i]->speed = rand() % 5 + 5;
    }
    return (rain);
}

void moving(dropplet_t **heal, int i)
{
    if (heal[i]->top > 720) {
        heal[i]->top = -10;
        heal[i]->bottom = 0;
    } else {
        heal[i]->top += 2 * heal[i]->speed;
        heal[i]->bottom += 2 * heal[i]->speed;
    }
}

void create_dropplet(framebuffer_t *framebuffer, dropplet_t **heal, int i)
{
    for (int j = heal[i]->top; j < heal[i]->bottom; j++)
        if (j > 0 && j < 720)
            put_pixel(framebuffer, heal[i]->x, j, sfBlue);
}