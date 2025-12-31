/*
** EPITECH PROJECT, 2024
** my_hunter.c
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

typedef struct ghost_s {
    sfSprite *sprite;
    int is_alive;
    double animation_timer;
    struct ghost_s *next;
} ghost_t;

typedef struct windows_s {
    sfRenderWindow * window_0;
} windows_t;

typedef struct textures_s {
    sfTexture *landscape;
    sfTexture *house;
    sfTexture *ghosts;
    sfTexture *button;
} textures_t;

typedef struct fonts_s {
    sfFont *help_me;
} fonts_t;

typedef struct sprites_s {
    sfSprite *landscape;
    sfSprite *house;
    sfSprite *button;
} sprites_t;

typedef struct texts_s {
    sfText *score;
    sfText *life;
} texts_t;

typedef struct musics_s {
    sfMusic *music_game;
} musics_t;

typedef struct clocks_s {
    sfClock *clock_system;
} clocks_t;

typedef struct linked_lists_s {
    struct ghost_s *ghosts;
} lists_t;

typedef struct global_vars_s {
    double delta;
    int is_playing;
    int score;
    int lifes;
    double time_between_ghosts;
    double time_before_next_ghost;
    double ghosts_speed;
} vars_t;

typedef struct all_s {
    struct windows_s *windows;
    struct textures_s *textures;
    struct fonts_s *fonts;
    struct sprites_s *sprites;
    struct texts_s *texts;
    struct musics_s *musics;
    struct clocks_s *clocks;
    struct linked_lists_s *lists;
    struct global_vars_s *vars;
} all_t;

#endif
