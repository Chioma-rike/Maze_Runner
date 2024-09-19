# Define the source files
SRC = maze_init.c maze.c color.c events.c

# Define the object files
OBJ = $(SRC:.c=.o)

# SDL2 flags
SDL2_FLAGS = $(shell sdl2-config --cflags --libs)

# Default target
all: game

# Rule to build the game
game: $(OBJ)
	@gcc -o game $(OBJ) $(SDL2_FLAGS) -lm -Wall -Werror -Wextra -pedantic

# Rule to compile each .c file into .o
%.o: %.c
	@gcc -c $< -o $@ $(SDL2_FLAGS) -Wall -Werror -Wextra -pedantic

# Clean up build files
clean:
	@rm -f $(OBJ) game
