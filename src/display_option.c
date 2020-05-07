/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** display element for the scene option
*/

#include "rpg.h"

static void display_opt_elt(game_t *game)
{
    sfVector2f but_pos = sfRectangleShape_getPosition(game->checkbox.rec);
    const char *music_text = "Music : ";

    but_pos.x -= 200;
    sfText_setColor(game->text.text, sfWhite);
    sfText_setString(game->text.text, music_text);
    sfText_setPosition(game->text.text, but_pos);
    sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
    sfRenderWindow_drawSprite(game->window.window, game->checkbox.sprite, NULL);
}

static void handle_chekcbox(but_t *check, game_t *game)
{
    sfVector2f m_pos = get_mouse_pos(game->window.window);

    if (button_is_clicked(check, m_pos)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (game->play_music > 0) {
            sfSprite_setTexture(check->sprite, check->tex_hoover, sfTrue);
        } else {
            sfSprite_setTexture(check->sprite, check->tex_norm, sfTrue);
        }
        game->play_music *= -1;
        for (int i = 0; i < 5 && game->play_music > 0; i++)
            sfMusic_setVolume(game->scene[i]->music, game->volume);
        for (int i = 0; i < 5 && game->play_music < 0; i++)
            sfMusic_setVolume(game->scene[i]->music, 0.0);
        sfSleep(sfMilliseconds(100));
    }
}

int display_option(game_t *game)
{
    handle_chekcbox(&(game->checkbox), game);
    display_opt_elt(game);
    return (0);
}