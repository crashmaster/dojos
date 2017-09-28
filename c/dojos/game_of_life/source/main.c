#include <stdio.h>
#include <stdlib.h>

#include "game_of_life.h"

void print_universe(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      if (universe[j][i] == ALIVE) {
        printf("\u25A0");
      }
      else {
        printf("\u25A1");
      }
    }
    printf("\n");
  }
}

int main() {
  int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      input_universe[i][j] = DEAD;
    }
  }

  input_universe[0][1] = 1;
  input_universe[1][2] = 1;
  input_universe[2][0] = 1;
  input_universe[2][1] = 1;
  input_universe[2][2] = 1;

  for (size_t i = 0; i < 80; i++) {
    int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];
    for (int i = 0; i < UNIVERSE_WIDTH; i++) {
      for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
        output_universe[i][j] = DEAD;
      }
    }

    system("clear");
    game_of_life(input_universe, output_universe);
    print_universe(output_universe);
    system("sleep 0.2");

    for (int i = 0; i < UNIVERSE_WIDTH; i++) {
      for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
        input_universe[i][j] = output_universe[i][j];
      }
    }
  }

  return 0;
}
