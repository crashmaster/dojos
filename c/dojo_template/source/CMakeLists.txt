include_directories(.)

add_executable(
    test_%%dojo_name%%
        %%dojo_name%%.c
        %%dojo_name%%.h
        test_%%dojo_name%%.c
        test_%%dojo_name%%.h
)
