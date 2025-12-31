/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** menu.c
*/

#include "../include/struct.h"

int display_menu(all_t *all)
{
    sfRenderWindow_drawSprite(
        all->windows->window_0, all->sprites->landscape, NULL);
    sfRenderWindow_drawSprite(
        all->windows->window_0, all->sprites->button, NULL);
    return 0;
}
