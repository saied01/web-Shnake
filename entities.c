#include "entities.h"
#include "utils.h"
#include <ncurses.h>
#include <stdint.h>

// Variables globales accesibles
Snake game_snake;
Food game_food;
int game_over_flag = 0;

void update_snake(int xmax, int ymax)
{
  for (int i = game_snake.length - 1; i > 0; --i)
  {
    game_snake.body[i] = game_snake.body[i - 1];
  }

  game_snake.body[0].x += game_snake.dx;
  game_snake.body[0].y += game_snake.dy;
}

void draw_snake() {}

void draw_food() {}

int update_food(int xmax, int ymax, int score)
{
  if (game_snake.body[0].x == game_food.x && game_snake.body[0].y == game_food.y)
  {
    game_snake.length++;
    score += 10;
    game_food.x = rand() % (xmax / 2 - 2) + 1;
    game_food.y = rand() % (ymax / 2 - 2) + 1;
  }
  return score;
}

void get_snake_data(int *length, int *head_x, int *head_y, int *body_x, int *body_y)
{
  *length = game_snake.length;
  *head_x = game_snake.body[0].x;
  *head_y = game_snake.body[0].y;
  for (int i = 0; i < game_snake.length; i++)
  {
    body_x[i] = game_snake.body[i].x;
    body_y[i] = game_snake.body[i].y;
  }
}

void get_food_data(int *x, int *y)
{
  *x = game_food.x;
  *y = game_food.y;
}

int is_game_over()
{
  return game_over_flag;
}
