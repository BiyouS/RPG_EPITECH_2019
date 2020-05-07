/*
** EPITECH PROJECT, 2020
** chose you player class
** File description:
** yeah tu choisit ton class
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

static void create_text(char *name, text_t *text)
{
    sfText_setString(text->text, name);
    sfText_setColor(text->text, sfBlack);
    sfText_setPosition(text->text, (sfVector2f){WIN_W / 2 - 300,
        WIN_H / 2 - 150});
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

static int text_entred(game_t *game)
{
    sfUint32 unicode = game->window.event.text.unicode;

    if ((sfEvtKeyReleased && sfEvtTextEntered &&
    (unicode == 109 || unicode == 103 || unicode == 97 || unicode == 100))) {
        if (unicode == 109)
            return 1;
        if (unicode == 103)
            return 2;
        if (unicode == 97)
            return 3;
        if (unicode == 100)
            return 4;
    }
    return 0;
}

int choose_player_class(game_t *game, UNSD player_t *player, int check)
{
    sfSprite *cspt = sfSprite_create();
    sfTexture *cttu = sfTexture_createFromFile("Assets/IMG/ciel.png", NULL);
    char *text_ = my_strdup("Choisit ta classe\nm pour choisir Mage,\n g pour\
    choisir Guerrier,\n a pour choisir Assasin,\n d pour choisir Druide.");
    int class = 0;

    create_text(text_, &game->text);
    sfSleep(sfMilliseconds(60));
    if (cttu == NULL)
        return 84;
    while (class == 0 && check != -1) {
        if (close_window(game) == -1)
            return -1;
        init_all(cspt, cttu);
        display_here(game, cspt);
        class = text_entred(game);
    }
    player->class = class;
    destroy(cspt, cttu);
    free(text_);
    return check;
}