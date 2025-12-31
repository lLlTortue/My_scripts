/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"

int my_hunter(void);

all_t *init_all(void);
int free_all(all_t *all);
int free_linked_lists(all_t *all);

int display_menu(all_t *all);
int play(all_t *all);

int manage_events(sfEvent *event, all_t *all);
int manage_ghosts(all_t *all);

int kill_ghost(ghost_t *ghost);

#endif
