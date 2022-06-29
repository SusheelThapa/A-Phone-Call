#! /usr/bin/bash

# Useful variables
file_to_compile="main.cpp src/*.cpp"
includes="-Iinclude/headers"
output_filename="main"
compiler_flags="-w"
SDL_library="-lSDL2 -lSDL2_image -lSDL2_ttf"

# print the command to compile files with SDL
echo "g++ $file_to_compile $includes $compiler_flags $SDL_library -o $output_filename"

# Compiling command
g++ $file_to_compile $includes $compiler_flags $SDL_library -o $output_filename
./$output_filename

# Remove the executable file
rm $output_filename
