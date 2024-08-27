CC = clang++
SRC = ./src/*.cpp  ./src/**/*.cpp ./src/**/**/*.cpp
TARGET = ./target/main.exe
FLAGS = -Wall -I ./src
SDL_FLAGS = -I ./../SDL/include/SDL2 -L ./../SDL_CLANG/SDL2-2.30.5/lib/x64 -L ./../SDL_CLANG/SDL2_image-2.8.2/lib/x64 -lSDL2main -lSDL2 -lSDL2_image

run: src/main.cpp
	@echo "==================================="
	$(CC) $(SRC) -o $(TARGET) $(FLAGS) $(SDL_FLAGS)
	$(TARGET)