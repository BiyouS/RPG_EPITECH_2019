/*
** EPITECH PROJECT, 2020
** gamestarter
** File description:
** game_starter
*/

#include "rpg.h"

const unsigned int WIN_W;
const unsigned int WIN_H;

int (* const func_menu[5])(game_t *game) = {
    go_to_new_game,
    continue_game,
    go_to_option,
    start_credit_anim,
    quit_game,
};

int (* const func_game[1])() = {
    go_to_help,
};

int (* const func_opt[3])() = {
    go_to_menu,
    diminue_vol,
    up_vol,
};

int (* const func_pause[3])() = {
    continue_game,
    go_to_menu,
    quit_game,
};

int (* const func_quest[1])() = {
    continue_game,
};

static int get_img_t(char *filepath, img_t *img)
{
    (*img).spr = sfSprite_create();
    if ((*img).spr == NULL)
        return (-1);
    (*img).tex = sfTexture_createFromFile(filepath, NULL);
    if ((*img).tex== NULL) {
        sfSprite_destroy((*img).spr);
        return (-1);
    }
    sfSprite_setTexture((*img).spr, (*img).tex, sfTrue);
    return (0);
}

static scene_t *get_a_scene(char *but_path, char *img_fp, size_t nb_but,
int (* const func_arr[])())
{
    scene_t *sce = malloc(sizeof(scene_t));

    if (sce == NULL)
        return (NULL);
    init_scene_var(sce, nb_but);
    if (but_path != NULL) {
        if (load_but_to_sce(sce, but_path) == -1)
            return (NULL);
    }
    if (img_fp != NULL) {
        if (get_img_t(img_fp, &sce->bg) == -1)
            return (NULL);
    }
    if (nb_but == 0)
        return (sce);
    sce->func_arr = malloc(sizeof(int *) * nb_but);
    if (sce->func_arr == NULL)
        return (NULL);
    for (size_t i = 0; i < nb_but; i++)
        sce->func_arr[i] = func_arr[i];
    return (sce);
}

static scene_t **get_scene(void)
{
    scene_t **scene = malloc(sizeof(scene_t *) * 10);

    if (!scene)
        return (NULL);
    scene[0] = get_a_scene("config/button_menu.txt", "Assets/IMG/map.png",
    5, func_menu);
    scene[1] = get_a_scene("config/button_game.txt", NULL, 1, func_game);
    scene[2] = get_a_scene("config/button_pause.txt", "Assets/IMG/map.png",
    3, func_pause);
    scene[3] = get_a_scene(NULL, "Assets/IMG/bg/bg1.png", 0, NULL);
    scene[4] = get_a_scene(NULL, "Assets/IMG/bg/bg2.png", 0, NULL);
    scene[5] = get_a_scene(NULL, "Assets/IMG/map.png", 0, NULL);
    scene[6] = get_a_scene("config/button_quest.txt", "Assets/IMG/map.png",
    1, func_quest);
    scene[7] = get_a_scene(NULL, "Assets/IMG/map.png", 0, NULL);
    scene[8] = get_a_scene("config/button_quest.txt", "Assets/IMG/help.png",
    1, func_quest);
    scene[9] = get_a_scene("config/button_opt.txt", "Assets/IMG/map.png",
    3, func_opt);
    return (scene);
}

static void draw_game(game_t *game)
{
    draw_map(game);
    draw_sprite_map(&(game->sprite_coll));
    draw_name_of_game(game);
    draw_generique(game);
    draw_ending(game);
    draw_credits(game);
    draw_perso(game);
}

bool game_starter(void)
{
    game_t game;
    char *sound_path[2] = {"Assets/IMG/son_on.png", "Assets/IMG/son_off.png"};

    if (init_game(&game) == -1)
        return (false);
    game.scene = get_scene();
    if (verif_scene(&game) == -1)
        return (false);
    draw_game(&game);
    game.idx_sce = 0;
    for (int i = 0; i < 5; i++)
        game.quest[i] = -1;
    game.volume = 8.0;
    game.play_music = 1;
    init_button(&(game.checkbox), (sfVector2f){600, 220}, (sfVector2f){75, 75});
    if (get_but_img(&(game.checkbox), sound_path, -1) == -1)
        return (false);
    sfSprite_setPosition(game.checkbox.sprite, (sfVector2f){600, 220});
    loop_window(&game, &(game.sprite_coll));
    return true;
}