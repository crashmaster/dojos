include_directories(.)

add_executable(
    game_of_life
        main.c
        game_of_life.c
        game_of_life.h
)

add_executable(
    test_game_of_life
        test_main.c
        game_of_life.c
        game_of_life.h
        test_game_of_life.c
        test_game_of_life.h
)
