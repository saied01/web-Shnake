#include "input.h"

extern Snake game_snake;

void handle_input(int direction)
{
  switch (direction)
  {
  case 0: // UP
    if (game_snake.dy != 1)
    {
      game_snake.dx = 0;
      game_snake.dy = -1;
    }
    break;
  case 1: // DOWN
    if (game_snake.dy != -1)
    {
      game_snake.dx = 0;
      game_snake.dy = 1;
    }
    break;
  case 2: // LEFT
    if (game_snake.dx != -1)
    {
      game_snake.dy = 0;
      game_snake.dx = -1;
    }
    break;
  case 3: // RIGHT
    if (game_snake.dx != 1)
    {
      game_snake.dy = 0;
      game_snake.dx = 1;
    }
    break;
  }
}
