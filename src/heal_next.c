/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** heal_next
*/

#include "rpg.h"

dropplet_t **init_heal(void)
{
    dropplet_t **heal = malloc(sizeof(dropplet_t *) * (499 + 1));

    for (int i = 0; i < 500; i++) {
        heal[i] = malloc(sizeof(dropplet_t));
        heal[i]->particle = (sfIntRect){heal[i]->x, 720, 5, 5};
        heal[i]->x = rand() % 1280;
        heal[i]->started = 0;
        heal[i]->speed = rand() % 5 + 5;
    }
    return (heal);
}

void moving_heal(dropplet_t **heal, int i)
{
    if (heal[i]->particle.top < 0) {
        heal[i]->particle.top = 720;
    } else {
        heal[i]->particle.top -= 2 * heal[i]->speed;
    }
}

static void create_dropplet_heal_next(dropplet_t **heal, \
framebuffer_t *fbuffer, int i)
{
    for (int j = heal[i]->x; j < heal[i]->x + 3; j++)
        for (int k = heal[i]->particle.top; \
k < heal[i]->particle.top + 3; k++)
            put_pixel(fbuffer, j, k, (sfColor){77, 255, 0, 255});
}

void create_dropplet_heal(framebuffer_t *fbuffer, \
dropplet_t **heal, int i, sfIntRect extract)
{
    if (heal[i]->particle.top > extract.top \
&& heal[i]->particle.top < extract.top + extract.height \
&& heal[i]->x > extract.left && heal[i]->x < extract.left + extract.width)
        create_dropplet_heal_next(heal, fbuffer, i);
}