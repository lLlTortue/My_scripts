/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** ghosts.c
*/

#include "../include/struct.h"

#include <stdio.h>
#include <stdlib.h>

int kill_ghost(ghost_t *ghost)
{
    sfIntRect r = sfSprite_getTextureRect(ghost->sprite);

    r.top = 4096;
    sfSprite_setTextureRect(ghost->sprite, r);
    ghost->is_alive = 0;
    return 0;
}

static int del_ghost(ghost_t *ghost_to_del, ghost_t *prev_ghost, all_t *all)
{
    if (!prev_ghost)
        all->lists->ghosts = ghost_to_del->next;
    else
        prev_ghost->next = ghost_to_del->next;
    sfSprite_destroy(ghost_to_del->sprite);
    free(ghost_to_del);
    return 0;
}

static int new_ghost(lists_t *lists, all_t *all)
{
    ghost_t *ghost = all->lists->ghosts;
    sfIntRect rect = {-25, 2304, 256, 256};
    sfVector2f position = {200 + rand() % 1520, 900};
    sfVector2f origin = {128, 128};

    lists->ghosts = malloc(sizeof(struct ghost_s));
    lists->ghosts->is_alive = 1;
    lists->ghosts->animation_timer = 0;
    lists->ghosts->sprite = sfSprite_create();
    sfSprite_setTexture(lists->ghosts->sprite, all->textures->ghosts, sfTrue);
    sfSprite_setTextureRect(lists->ghosts->sprite, rect);
    sfSprite_setPosition(lists->ghosts->sprite, position);
    sfSprite_setOrigin(lists->ghosts->sprite, origin);
    lists->ghosts->next = ghost;
    return 0;
}

static int update_position(sfSprite *ghost, vars_t *vars)
{
    sfVector2f position;

    position = sfSprite_getPosition(ghost);
    position.y -= vars->ghosts_speed;
    sfSprite_setPosition(ghost, position);
    return 0;
}

static int update_rect(ghost_t *ghost, all_t *all)
{
    sfIntRect rect = sfSprite_getTextureRect(ghost->sprite);

    rect.left += 256;
    if (rect.left == 3047 && ghost->is_alive) {
        rect.left = -25;
    }
    sfSprite_setTextureRect(ghost->sprite, rect);
    return 0;
}

static int update_animation(ghost_t *ghost, all_t *all)
{
    ghost->animation_timer += all->vars->delta;
    if (ghost->animation_timer > 0.1) {
        ghost->animation_timer = 0;
        update_rect(ghost, all);
    }
    return 0;
}

static int test_to_del(ghost_t *ghost, ghost_t *prev_ghost, all_t *all)
{
    if (sfSprite_getTextureRect(ghost->sprite).left > 5500) {
        del_ghost(ghost, prev_ghost, all);
        all->vars->score += 10;
        if (all->vars->ghosts_speed < 1.5)
            all->vars->ghosts_speed += 0.01;
        if (all->vars->time_between_ghosts > 2)
            all->vars->time_between_ghosts -= 0.15;
        return 0;
    }
    if (ghost->is_alive && sfSprite_getPosition(ghost->sprite).y < -70) {
        del_ghost(ghost, prev_ghost, all);
        all->vars->lifes -= 1;
    }
    return 0;
}

static int update_ghosts(ghost_t *ghosts, all_t *all)
{
    ghost_t *prev_ghost = 0;

    while (ghosts != 0) {
        update_position(ghosts->sprite, all->vars);
        update_animation(ghosts, all);
        sfRenderWindow_drawSprite(
            all->windows->window_0, ghosts->sprite, NULL);
        test_to_del(ghosts, prev_ghost, all);
        prev_ghost = ghosts;
        ghosts = ghosts->next;
    }
    return 0;
}

int manage_ghosts(all_t *all)
{
    all->vars->time_before_next_ghost -= all->vars->delta;
    if (all->vars->time_before_next_ghost <= 0) {
        all->vars->time_before_next_ghost = all->vars->time_between_ghosts;
        new_ghost(all->lists, all);
    }
    update_ghosts(all->lists->ghosts, all);
    return 0;
}
