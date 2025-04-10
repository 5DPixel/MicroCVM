add_executable(test_main mov.c ../src/implementation/cpu.c)

target_include_directories(test_main PRIVATE ../include)

add_test(NAME TestMain COMMAND test_main)