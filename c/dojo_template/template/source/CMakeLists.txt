include_directories(.)

add_executable(
    test_%%dojo_name%%
        test_main.c
        %%dojo_name%%.c
        %%dojo_name%%.h
        test_%%dojo_name%%.c
        test_%%dojo_name%%.h
)
