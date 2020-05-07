/*
** EPITECH PROJECT, 2020
** chose you player
** File description:
** yeah tu choisit ton perso
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

static void create_text(char *name, text_t *text)
{
    sfText_setString(text->text, name);
    sfText_setColor(text->text, sfBlack);
    sfText_setPosition(text->text, (sfVector2f){WIN_W / 2 - 200, WIN_H / 2});
}

static char *text_entred(game_t *game, char *name)
{
    sfUint32 unicode = game->window.event.text.unicode;
    char letter;
    char temp[2];

    if (sfKeyboard_isKeyPressed(sfKeyBack) && my_strlen(name) >= 8)
        name[my_strlen(name) - 1] = '\0';
    else if ((sfEvtKeyReleased && sfEvtTextEntered &&
    unicode >= 'a' && unicode <= 'z') || (unicode >= 'A' && unicode <= 'Z')) {
        letter = unicode;
        temp[0] = letter;
        temp[1] = '\0';
        name = strcat_dup(name, temp);
    }
    unicode = 0;
    sfSleep(sfMilliseconds(40));
    return name;
}

static void ciel(game_t *game, sfSprite* sciel, sfTexture *tciel)
{
    sfSprite_setTexture(sciel, tciel, sfFalse);
    sfSprite_setScale(sciel, (sfVector2f){2, 2.5});
    sfSprite_setPosition(sciel, (sfVector2f){0, 0});
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window, sciel, NULL);
    sfRenderWindow_drawText(game->window.window, game->text.text, NULL);
    sfRenderWindow_display(game->window.window);
}

int choose_player_name(game_t *game, UNSD player_t *player, int check)
{
    sfSprite *ciel_spt = sfSprite_create();
    sfTexture *ciel_ttu = sfTexture_createFromFile("Assets/IMG/ciel.png", NULL);
    char *name = my_strdup("Pseudo:");

    create_text(name, &game->text);
    while (check != -1) {
        if (close_window(game) == -1 || ciel_ttu == NULL)
            return -1;
        if (sfKeyboard_isKeyPressed(sfKeyReturn) && my_strlen(name) > 7)
            break;
        if (sfKeyboard_isKeyPressed(sfKeyBack) && my_strlen(name) >= 8)
            name[my_strlen(name) - 1] = '\0';
        if (my_strlen(name) <= 26 && sfEvtTextEntered)
            name = text_entred(game, name);
        sfText_setString(game->text.text, name);
        ciel(game, ciel_spt, ciel_ttu);
    }
    player->name = my_strdup(name + my_strlen("Pseudo:"));
    destroy(ciel_spt, ciel_ttu);
    free(name);
    return check;
}