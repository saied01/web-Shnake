#include "board.h"
#include "entities.h"
#include "input.h"
#include "utils.h"

int xmax = 30;
int ymax = 20;
int score = 0;

extern Snake game_snake;
extern Food game_food;
extern int game_over_flag;

// Funciones exportadas para WebAssembly
void init_game()
{
  score = 0;
  game_over_flag = 0;

  game_snake.length = 2;
  game_snake.dx = 1;
  game_snake.dy = 0;
  game_snake.body[0].x = xmax / 2;
  game_snake.body[0].y = ymax / 2;
  game_snake.body[1].x = xmax / 2 - 1;
  game_snake.body[1].y = ymax / 2;

  game_food.x = rand() % (xmax - 2) + 1;
  game_food.y = rand() % (ymax - 2) + 1;
}

void update_game()
{
  update_snake(xmax, ymax);

  // Colisión con bordes
  if (game_snake.body[0].x <= 0 || game_snake.body[0].x >= xmax - 1 ||
      game_snake.body[0].y <= 0 || game_snake.body[0].y >= ymax - 1)
  {
    game_over_flag = 1;
    return;
  }

  // Colisión consigo misma
  for (int i = 1; i < game_snake.length; i++)
  {
    if (game_snake.body[0].x == game_snake.body[i].x &&
        game_snake.body[0].y == game_snake.body[i].y)
    {
      game_over_flag = 1;
      return;
    }
  }

  score = update_food(xmax, ymax, score);
}

int get_score()
{
  return score;
}

void process_input(int direction)
{
  handle_input(direction);
}
