/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** play_game.c
*/

#include "../include/my.h"

#include <stdio.h>
#include <stdlib.h>

static int my_intlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        len += 1;
    }
    return len;
}

static char *int_to_str(int nb)
{
    int len = my_intlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));

    str[len] = '\0';
    for (int i = 1; i <= len; i++) {
        str[len - i] = nb % 10 + '0';
        nb /= 10;
    }
    return str;
}

static int display_score(all_t *all)
{
    char *score = int_to_str(all->vars->score);

    sfText_setString(all->texts->score, score);
    free(score);
    sfRenderWindow_drawText(
        all->windows->window_0, all->texts->score, NULL);
    return 0;
}

static int display_lifes(all_t *all)
{
    char *lifes = int_to_str(all->vars->lifes);

    sfText_setString(all->texts->life, lifes);
    free(lifes);
    sfRenderWindow_drawText(
        all->windows->window_0, all->texts->life, NULL);
    return 0;
}

int play(all_t *all)
{
    sfRenderWindow_drawSprite(
        all->windows->window_0, all->sprites->landscape, NULL);
    manage_ghosts(all);
    sfRenderWindow_drawSprite(
        all->windows->window_0, all->sprites->house, NULL);
    display_score(all);
    display_lifes(all);
    return 0;
}
