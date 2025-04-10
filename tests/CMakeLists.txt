add_executable(test_main mov.c ../src/implementation/cpu.c ../src/implementation/assemble/assemble.c ../src/implementation/disk.c)

target_include_directories(test_main PRIVATE ../include)

add_test(NAME TestMain COMMAND test_main)