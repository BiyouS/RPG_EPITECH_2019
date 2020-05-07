/*
** EPITECH PROJECT, 2020
** function associate to button of the menu scene
** File description:
** my_rpg
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

int go_to_new_game(game_t *game)
{
    for (int i = 0; i != 5; i++)
        game->quest[i] = -1;
    game->idx_sce = 1;
    free_player(game->player);
    game->player = init_perso();
    draw_sprite_map(&(game->sprite_coll));
    draw_map(game);
    draw_generique(game);
    init_hitbox_donjon(game);
    game->donjon.art_1 = 0;
    game->donjon.art_2 = 0;
    game->donjon.art_3 = 0;
    for (int i = 0; i < 10; i++)
        game->player->inventory[i] = -1;
    return (0);
}

int go_to_option(game_t *game)
{
    game->idx_sce = 9;
    return (0);
}

int go_to_credits(game_t *game)
{
    game->idx_sce = 4;
    return 0;
}

int quit_game(game_t *game)
{
    sfRenderWindow_close(game->window.window);
    return (0);
}

int start_credit_anim(game_t *game)
{
    int check = 0;

    do {
        close_window(game);
        sfRenderWindow_clear(game->window.window, sfBlack);
        check = credits_anim(game);
        sfRenderWindow_display(game->window.window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            break;
    } while (check != 1);
    game->sprite[4]->pos = (sfVector2f){WIN_W / 2, WIN_H * 2};
    sfSprite_setPosition(game->sprite[4]->sprite, game->sprite[4]->pos);
    return (0);
}
