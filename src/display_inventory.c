/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display the inventory
*/

#include "rpg.h"

static void display_item(game_t *game, sfSprite *spr, sfTexture **tex_arr,
sfRectangleShape **inv)
{
    sfVector2f pos = { 0, 0};

    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawRectangleShape(game->window.window, inv[i], NULL);
    for (int i = 0; i < 10; i++) {
        if (game->player->inventory[i] > 0) {
            sfSprite_setTexture(spr, tex_arr[game->player->inventory[i] - 1],
            sfFalse);
            pos = sfRectangleShape_getPosition(inv[i]);
            sfSprite_setPosition(spr, pos);
            sfRenderWindow_drawSprite(game->window.window, spr, NULL);
        }
    }
}

static void display_stat(game_t *game)
{
    sfVector2f pos = {450, 500};
    char *text = NULL;
    int stat[3] = {game->player->pv, game->player->mana, game->player->level};

    for (int i = 0; i < 3; i++) {
        text = my_int_to_str(stat[i]);
        if (!text)
            continue;
        sfText_setString(game->text.text, text);
        sfText_setPosition(game->text.text, pos);
        sfRenderWindow_drawSprite(game->window.window,
        game->hud.sprites[i + 3], NULL);
        sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
        free(text);
        pos.x += 150;
    }
}

static void set_sprite_pos(game_t *game, int opt)
{
    const sfVector2f init_pos[3] = {
        (sfVector2f){25, 635},
        (sfVector2f){1170, 620},
        (sfVector2f){115, 630},
    };
    const sfVector2f stat_pos[3] = {
        (sfVector2f){425, 485},
        (sfVector2f){565, 475},
        (sfVector2f){730, 490},
    };

    for (int i = 0; i < 3; i++) {
        if (opt == 0)
            sfSprite_setPosition(game->hud.sprites[i + 3], stat_pos[i]);
        if (opt == 1)
            sfSprite_setPosition(game->hud.sprites[i + 3], init_pos[i]);
    }
}

void display_inventory(game_t *game, sfSprite *spr, sfTexture **tex_arr,
sfRectangleShape **inv)
{
    set_sprite_pos(game, 0);
    sfRenderWindow_clear(game->window.window, sfBlack);
    close_window(game);
    display_map(game, &(game->sprite_coll), game->player);
    display_item(game, spr, tex_arr, inv);
    display_stat(game);
    heal(game->window.window, game, (sfIntRect){420, 480, 90, 90});
    display_cursor(game->sprite[5], game->window);
    sfRenderWindow_display(game->window.window);
    set_sprite_pos(game, 1);
}