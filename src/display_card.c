/*
** EPITECH PROJECT, 2020
** dsf
** File description:
** fsd
*/

#include "rpg.h"

void display_card(card_t **deck, int *tab, window_t window)
{
    float x = 300;
    float y = 450;
    sfSprite *sprite = NULL;

    for (int i = 0; i != 4; i++) {
        if (deck[i] != NULL && tab[i] != -1) {
            sprite = deck[tab[i]]->img.spr;
            sfSprite_setPosition(sprite, (sfVector2f){x, y});
            sfRenderWindow_drawSprite(window.window, sprite, NULL);
        }
        x += 175;
    }
}