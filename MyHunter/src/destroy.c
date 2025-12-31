/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** destroy.c
*/

#include "../include/struct.h"

#include <stdlib.h>

static int free_windows(all_t *all)
{
    sfRenderWindow_destroy(all->windows->window_0);
    free(all->windows);
    return 0;
}

static int free_textures(all_t *all)
{
    sfTexture_destroy(all->textures->landscape);
    sfTexture_destroy(all->textures->house);
    sfTexture_destroy(all->textures->button);
    sfTexture_destroy(all->textures->ghosts);
    free(all->textures);
    return 0;
}

static int free_fonts(all_t *all)
{
    sfFont_destroy(all->fonts->help_me);
    free(all->fonts);
    return 0;
}

static int free_background_sprites(all_t *all)
{
    sfSprite_destroy(all->sprites->house);
    sfSprite_destroy(all->sprites->landscape);
    sfSprite_destroy(all->sprites->button);
    free(all->sprites);
    return 0;
}

static int free_texts(all_t *all)
{
    sfText_destroy(all->texts->score);
    sfText_destroy(all->texts->life);
    free(all->texts);
    return 0;
}

static int free_musics(all_t *all)
{
    sfMusic_destroy(all->musics->music_game);
    free(all->musics);
    return 0;
}

static int free_clocks(all_t *all)
{
    sfClock_destroy(all->clocks->clock_system);
    free(all->clocks);
    return 0;
}

int free_linked_lists(all_t *all)
{
    ghost_t *ghosts = all->lists->ghosts;

    while (all->lists->ghosts != 0) {
        sfSprite_destroy(ghosts->sprite);
        all->lists->ghosts = all->lists->ghosts->next;
        free(ghosts);
        ghosts = all->lists->ghosts;
    }
    return 0;
}

static int free_global_vars(all_t *all)
{
    free(all->vars);
    return 0;
}

int free_all(all_t *all)
{
    free_windows(all);
    free_textures(all);
    free_fonts(all);
    free_background_sprites(all);
    free_texts(all);
    free_musics(all);
    free_clocks(all);
    free_linked_lists(all);
    free(all->lists);
    free_global_vars(all);
    free(all);
    return 0;
}
