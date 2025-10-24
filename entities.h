#ifndef ENTITIES_H
#define ENTITIES_H

#include "stdio.h"
#include "stdlib.h"
#include "utils.h"
#include <stdint.h>

void draw_snake();
void update_snake(int, int);
void draw_food();
int update_food(int, int, int);

// Funciones para exportar datos a JavaScript
void get_snake_data(int *length, int *head_x, int *head_y, int *body_x, int *body_y);
void get_food_data(int *x, int *y);
int is_game_over();

#endif
