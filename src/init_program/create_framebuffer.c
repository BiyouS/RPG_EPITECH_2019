/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_framebuffer
*/

#include "rpg.h"

framebuffer_t *create_framebuffer(int height, int width)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    if (framebuffer == NULL)
        return (NULL);
    int size = (height * width * 4);
    framebuffer->x = width;
    framebuffer->y = height;
    framebuffer->pixels = malloc(sizeof(sfUint8) * size);
    if (framebuffer->pixels == NULL) {
        free(framebuffer);
        return (NULL);
    }
    return (framebuffer);
}