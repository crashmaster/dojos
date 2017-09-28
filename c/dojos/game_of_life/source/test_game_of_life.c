#include <stdio.h>
#include <assert.h>

#include "game_of_life.h"


struct cell {
  int x;
  int y;
};


void print_universe(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      printf("[%d]", universe[j][i]);
    }
    printf("\n");
  }
}

void print_universes(int universe_a[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                     int universe_b[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  printf("Input universe:\n");
  print_universe(universe_a);
  printf("\nOutput universe:\n");
  print_universe(universe_b);
  printf("\n");
}

void assert_the_whole_universe_is_dead(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      assert(universe[i][j] == DEAD);
    }
  }
}

void assert_the_two_universes_are_the_same(int universe_a[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                           int universe_b[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      assert(universe_a[i][j] == universe_b[i][j]);
    }
  }
}

void set_all_cells_in_universe_to_dead(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  for (int i = 0; i < UNIVERSE_WIDTH; i++) {
    for (int j = 0; j < UNIVERSE_HEIGHT; j++)  {
      universe[i][j] = DEAD;
    }
  }
}

void set_alive_cells_in_universe(int universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                 struct cell alive_cells[],
                                 const size_t number_of_alive_cells) {
  set_all_cells_in_universe_to_dead(universe);
  for (size_t i=0; i < number_of_alive_cells; i++) {
    universe[alive_cells[i].x][alive_cells[i].y] = ALIVE;
  }
}

void call_game_of_life(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                       int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  game_of_life(input_universe, output_universe);
  print_universes(input_universe, output_universe);
}

void test_dead_universe_remains_dead(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                     int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  set_all_cells_in_universe_to_dead(input_universe);
  set_all_cells_in_universe_to_dead(output_universe);

  call_game_of_life(input_universe, output_universe);

  assert_the_whole_universe_is_dead(output_universe);
}

void test_one_alive_cell_is_going_to_die(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                         int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  struct cell alive_cells[] = {{1, 1}};
  const size_t number_of_alive_cells = sizeof(alive_cells)/sizeof(alive_cells[0]);
  set_alive_cells_in_universe(input_universe, alive_cells, number_of_alive_cells);
  set_all_cells_in_universe_to_dead(output_universe);

  call_game_of_life(input_universe, output_universe);

  assert_the_whole_universe_is_dead(output_universe);
}

void test_two_neighbor_cells_are_going_to_die(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                              int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  struct cell alive_cells[] = {{1, 1}, {1, 2}};
  const size_t number_of_alive_cells = sizeof(alive_cells)/sizeof(alive_cells[0]);
  set_alive_cells_in_universe(input_universe, alive_cells, number_of_alive_cells);
  set_all_cells_in_universe_to_dead(output_universe);

  call_game_of_life(input_universe, output_universe);

  assert_the_whole_universe_is_dead(output_universe);
}

void test_dying_and_born(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                         int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  set_all_cells_in_universe_to_dead(output_universe);

  struct cell alive_cells[] = {{1, 1}, {2, 1}, {1, 2}, {2, 2}, {1, 3}};
  size_t number_of_alive_cells = sizeof(alive_cells)/sizeof(alive_cells[0]);
  set_alive_cells_in_universe(input_universe, alive_cells, number_of_alive_cells);

  call_game_of_life(input_universe, output_universe);

  struct cell expected_alive_cells[] = {{0, 2}, {1, 1}, {2, 1}, {1, 3}, {2, 3}};
  number_of_alive_cells = sizeof(expected_alive_cells)/sizeof(expected_alive_cells[0]);
  int expcted_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];
  set_alive_cells_in_universe(expcted_universe, expected_alive_cells, number_of_alive_cells);

  assert_the_two_universes_are_the_same(expcted_universe, output_universe);
}

void test_dead_cell_having_three_alive_neighbors_becomes_alive(int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT],
                                                               int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT]) {
  set_all_cells_in_universe_to_dead(output_universe);

  struct cell alive_cells[] = {{1, 1}, {2, 1}, {2, 2}};
  size_t number_of_alive_cells = sizeof(alive_cells)/sizeof(alive_cells[0]);
  set_alive_cells_in_universe(input_universe, alive_cells, number_of_alive_cells);

  call_game_of_life(input_universe, output_universe);

  struct cell expected_alive_cells[] = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
  number_of_alive_cells = sizeof(expected_alive_cells)/sizeof(expected_alive_cells[0]);
  int expcted_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];
  set_alive_cells_in_universe(expcted_universe, expected_alive_cells, number_of_alive_cells);

  assert_the_two_universes_are_the_same(expcted_universe, output_universe);
}

void test_game_of_life() {
  int input_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];
  int output_universe[UNIVERSE_WIDTH][UNIVERSE_HEIGHT];

  printf("test_dead_universe_remains_dead:\n");
  test_dead_universe_remains_dead(input_universe, output_universe);
  printf("test_one_alive_cell_is_going_to_die:\n");
  test_one_alive_cell_is_going_to_die(input_universe, output_universe);
  printf("test_two_neighbor_cells_are_going_to_die:\n");
  test_two_neighbor_cells_are_going_to_die(input_universe, output_universe);
  printf("test_dying_and_born:\n");
  test_dying_and_born(input_universe, output_universe);
  printf("test_dead_cell_having_three_alive_neighbors_becomes_alive:\n");
  test_dead_cell_having_three_alive_neighbors_becomes_alive(input_universe, output_universe);
}
