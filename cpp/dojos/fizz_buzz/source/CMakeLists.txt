include_directories(.)

add_executable(
    test_fizz_buzz
        fizz_buzz.cpp
        fizz_buzz.hpp
        test_fizz_buzz.cpp
        test_fizz_buzz_helper.hpp
)

target_link_libraries(test_fizz_buzz ${GTEST_LIBRARIES} pthread)
