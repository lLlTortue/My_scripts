/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** init.c
*/

#include "../include/struct.h"

#include <stdlib.h>
#include <assert.h>

static int init_windows(all_t *all)
{
    sfVideoMode mode_0 = {1920, 1080, 32};

    all->windows = malloc(sizeof(struct windows_s));
    all->windows->window_0 = sfRenderWindow_create(
        mode_0, "SFML window", sfClose, NULL);
    return 0;
}

static int init_textures(all_t *all)
{
    all->textures = malloc(sizeof(struct textures_s));
    all->textures->landscape = sfTexture_createFromFile(
        "/home/l/My_scripts/MyHunter/images/back.jpg", NULL);
    all->textures->house = sfTexture_createFromFile(
        "/home/l/My_scripts/MyHunter/images/image.png", NULL);
    all->textures->ghosts = sfTexture_createFromFile(
        "/home/l/My_scripts/MyHunter/images/ghosts.png", NULL);
    all->textures->button = sfTexture_createFromFile(
        "/home/l/My_scripts/MyHunter/images/button-play.png", NULL);
    return 0;
}

static int init_fonts(all_t *all)
{
    all->fonts = malloc(sizeof(struct fonts_s));
    all->fonts->help_me = sfFont_createFromFile(
        "/home/l/My_scripts/MyHunter/fonts/font.ttf");
    assert(all->fonts->help_me);
    return 0;
}

static int init_background_sprites(all_t *all)
{
    sfVector2f scale = {0.75, 0.75};

    all->sprites = malloc(sizeof(struct sprites_s));
    all->sprites->landscape = sfSprite_create();
    sfSprite_setTexture(
        all->sprites->landscape, all->textures->landscape, sfTrue);
    sfSprite_setScale(all->sprites->landscape, scale);
    all->sprites->house = sfSprite_create();
    sfSprite_setTexture(
        all->sprites->house, all->textures->house, sfTrue);
    sfSprite_setScale(all->sprites->house, scale);
    all->sprites->button = sfSprite_create();
    sfSprite_setTexture(
        all->sprites->button, all->textures->button, sfTrue);
    return 0;
}

static int init_texts(all_t *all)
{
    sfVector2f position1 = {50, 20};
    sfVector2f position2 = {1800, 20};

    all->texts = malloc(sizeof(struct texts_s));
    all->texts->score = sfText_create();
    sfText_setFont(all->texts->score, all->fonts->help_me);
    sfText_setPosition(all->texts->score, position1);
    sfText_setCharacterSize(all->texts->score, 100);
    sfText_setColor(all->texts->score, sfWhite);
    all->texts->life = sfText_create();
    sfText_setFont(all->texts->life, all->fonts->help_me);
    sfText_setPosition(all->texts->life, position2);
    sfText_setCharacterSize(all->texts->life, 100);
    sfText_setColor(all->texts->life, sfRed);
    return 0;
}

static int init_musics(all_t *all)
{
    all->musics = malloc(sizeof(struct musics_s));
    all->musics->music_game = sfMusic_createFromFile(
        "/home/l/My_scripts/MyHunter/musics/music.ogg");
    return 0;
}

static int init_clocks(all_t *all)
{
    all->clocks = malloc(sizeof(struct clocks_s));
    all->clocks->clock_system = sfClock_create();
    return 0;
}

static int init_linked_lists(all_t *all)
{
    all->lists = malloc(sizeof(struct linked_lists_s));
    all->lists->ghosts = 0;
    return 0;
}

static int init_global_vars(all_t *all)
{
    all->vars = malloc(sizeof(struct global_vars_s));
    all->vars->delta = 0;
    all->vars->is_playing = 0;
    return 0;
}

all_t *init_all(void)
{
    all_t *all = malloc(sizeof(struct all_s));

    init_windows(all);
    init_textures(all);
    init_fonts(all);
    init_background_sprites(all);
    init_texts(all);
    init_musics(all);
    init_clocks(all);
    init_linked_lists(all);
    init_global_vars(all);
    return all;
}
