/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** function to destroy the button array
*/

#include "rpg.h"

void destroy_button_arr(but_t **but)
{
    for (int i = 0; but[i] != NULL; i++) {
        sfRectangleShape_destroy(but[i]->rec);
        sfSprite_destroy(but[i]->sprite);
        sfTexture_destroy(but[i]->tex_hoover);
        sfTexture_destroy(but[i]->tex_norm);
        free(but[i]);
    }
    free(but);
}