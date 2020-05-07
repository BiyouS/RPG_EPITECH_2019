/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** put_pixel
*/

#include "rpg.h"

void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    int pixel = (y * framebuffer->x + x) * 4;

    framebuffer->pixels[pixel] = color.r;
    framebuffer->pixels[pixel + 1] = color.g;
    framebuffer->pixels[pixel + 2] = color.b;
    framebuffer->pixels[pixel + 3] = color.a;
}

void display_framebuffer(framebuffer_t *framebuffer, sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_create(1280, 720);
    sfSprite *sprite = sfSprite_create();

    sfTexture_updateFromPixels(texture, framebuffer->pixels, \
1280, 720, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}