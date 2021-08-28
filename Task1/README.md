# Task 1 C++ course INFT2503 at NTNU

## Important
Task b (b.cpp) reads from the temperatures.txt file. It can only read from this if the built version of b.cpp is in the same directory as the temperatures file.
There is therefore a command in CMakeLists.txt, which copies the temperatures.txt file into the build directory. Here the destination has to be set to the build directory in use:
```
file(COPY "temperatures.txt" DESTINATION "../example_build_directory")
```
Manually copying the temperatures.txt file is also possible (even though not recommended because an update to the file, means manually copying it again is necessary.

## Flags
In the CMakeLists.txt the -Wall -Wextra flag is set through the following command:
```
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
```