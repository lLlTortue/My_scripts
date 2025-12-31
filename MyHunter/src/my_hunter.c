/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** my_hunter.c
*/

#include "../include/my.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static int update(all_t *all)
{
    all->vars->delta = sfClock_restart(
        all->clocks->clock_system).microseconds / 1000000.;
    if (!all->vars->is_playing)
        display_menu(all);
    else
        play(all);
    return 0;
}

static int launch_loop(all_t *all)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(all->windows->window_0)) {
        if (manage_events(&event, all))
            return 0;
        update(all);
        sfRenderWindow_display(all->windows->window_0);
        if (all->vars->lifes <= 0) {
            all->vars->is_playing = 0;
            free_linked_lists(all);
        }
    }
    return 0;
}

int my_hunter(void)
{
    all_t *all = init_all();

    srand(time(NULL));
    sfMusic_play(all->musics->music_game);
    sfMusic_setLoop(all->musics->music_game, sfTrue);
    sfClock_restart(all->clocks->clock_system);
    launch_loop(all);
    return 0;
}
