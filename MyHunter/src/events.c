/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** events.c
*/

#include "../include/my.h"

int compare_positions(sfMouseButtonEvent event, ghost_t *ghost)
{
    sfFloatRect b = sfSprite_getGlobalBounds(ghost->sprite);
    int xtest = event.x > b.left && event.x < b.left + b.width;
    int ytest = event.y > b.top && event.y < b.top + b.height;

    if (xtest && ytest)
        return 1;
    return 0;
}

static int reinit_vars(vars_t *vars)
{
    vars->score = 0;
    vars->lifes = 3;
    vars->ghosts_speed = 0.075;
    vars->time_between_ghosts = 5;
    vars->time_before_next_ghost = 2;
    return 0;
}

static int manage_mouse_click(sfMouseButtonEvent event, all_t *all)
{
    ghost_t *ghosts = all->lists->ghosts;

    if (!all->vars->is_playing) {
        reinit_vars(all->vars);
        all->vars->is_playing = 1;
        return 0;
    }
    while (ghosts != 0) {
        if (compare_positions(event, ghosts)) {
            kill_ghost(ghosts);
        }
        ghosts = ghosts->next;
    }
    return 0;
}

static int analyse_events(sfEvent *event, all_t *all)
{
    if (event->type == sfEvtMouseButtonPressed) {
        manage_mouse_click(event->mouseButton, all);
        return 0;
    }
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(all->windows->window_0);
        free_all(all);
        return 1;
    }
    return 0;
}

int manage_events(sfEvent *event, all_t *all)
{
    while (sfRenderWindow_pollEvent(all->windows->window_0, event))
        if (analyse_events(event, all))
            return 1;
    return 0;
}
