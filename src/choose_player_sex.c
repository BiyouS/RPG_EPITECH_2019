/*
** EPITECH PROJECT, 2020
** chose you player sex
** File description:
** yeah tu choisit ton sexe
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

static void create_text(char *name, text_t *text)
{
    sfText_setString(text->text, name);
    sfText_setColor(text->text, sfBlack);
    sfText_setPosition(text->text, (sfVector2f){WIN_W / 2 - 300, WIN_H / 2});
}

static void display_here(game_t *game, sfSprite* ciel)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window, ciel, NULL);
    sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
    sfRenderWindow_display(game->window.window);
}

static void init_all(sfSprite* sciel, sfTexture *tciel)
{
    sfSprite_setTexture(sciel, tciel, sfFalse);
    sfSprite_setScale(sciel, (sfVector2f){2, 2.5});
    sfSprite_setPosition(sciel, (sfVector2f){0, 0});
}

static int text_entred(game_t *game, int *genre)
{
    sfUint32 unicode = game->window.event.text.unicode;

    if ((sfEvtKeyReleased && sfEvtTextEntered &&
    (unicode == 109 || unicode == 102))) {
        if (unicode == 109) {
            (*genre) = 1;
            return (-1);
        } else if (unicode == 102) {
            (*genre) = 2;
            return (-1);
        }
    }
    return 0;
}

int choose_player_sex(game_t *game, UNSD player_t *player, int check)
{
    sfSprite *ciel_spt = sfSprite_create();
    sfTexture *ciel_ttu = sfTexture_createFromFile("Assets/IMG/ciel.png",
    NULL);
    char *text_ = my_strdup("Appuie sur m pour homme ou f pour femme.");
    int genre = 1;

    create_text(text_, &game->text);
    while (check != -1) {
        if (close_window(game) == -1 || ciel_ttu == NULL)
            return -1;
        init_all(ciel_spt, ciel_ttu);
        display_here(game, ciel_spt);
        if (text_entred(game, &genre) == -1)
            break;
    }
    init_genre(player, genre);
    destroy(ciel_spt, ciel_ttu);
    free(text_);
    return check;
}