#include "game_of_life.h"

int get_number_of_neighbors_of_cell(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT], int x, int y) {
  int number_of_neighbors = 0;
  if (x-1 >= 0) {
    if (universe[x-1][y] == ALIVE) {
      number_of_neighbors++;
    }
    if (y-1 >= 0) {
      if (universe[x-1][y-1] == ALIVE) {
        number_of_neighbors++;
      }
    }
    if (y+1 < UNIVERSE_HEIGHT) {
      if (universe[x-1][y+1] == ALIVE) {
        number_of_neighbors++;
      }
    }
  }
  if (x+1 < UNIVERSE_WIDTH) {
    if (universe[x+1][y] == ALIVE) {
      number_of_neighbors++;
    }
    if (y-1 >= 0) {
      if (universe[x+1][y-1] == ALIVE) {
        number_of_neighbors++;
      }
    }
    if (y+1 < UNIVERSE_HEIGHT) {
      if (universe[x+1][y+1] == ALIVE) {
        number_of_neighbors++;
      }
    }
  }
  if (y-1 >= 0) {
    if (universe[x][y-1] == ALIVE) {
      number_of_neighbors++;
    }
  }
  if (y+1 < UNIVERSE_HEIGHT) {
    if (universe[x][y+1] == ALIVE) {
      number_of_neighbors++;
    }
  }

  return number_of_neighbors;
}

void game_of_life(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                  int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      int number_of_neighbors = get_number_of_neighbors_of_cell(input_universe, i, j);
      if (input_universe[i][j] == ALIVE) {
        if (number_of_neighbors >= 2 && number_of_neighbors < 4) {
          output_universe[i][j] = ALIVE;
        }
      }
      if (input_universe[i][j] == DEAD) {
        if (number_of_neighbors == 3) {
          output_universe[i][j] = ALIVE;
        }
      }
    }
  }
}
