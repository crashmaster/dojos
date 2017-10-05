include_directories(.)

add_executable(
    test_%%dojo_name%%
        %%dojo_name%%.cpp
        %%dojo_name%%.hpp
        test_%%dojo_name%%.cpp
        test_%%dojo_name%%.hpp
)

target_link_libraries(test_%%dojo_name%% ${GTEST_LIBRARIES} pthread)
