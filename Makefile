TARGET = game

CC = emcc
CFLAGS = -O2
WASM_FLAGS = -s WASM=1 -s ENVIRONMENT=web \
             -s EXPORTED_FUNCTIONS="['_init_game','_update_game','_get_snake_data','_get_food_data','_get_score','_is_game_over','_process_input']" \
             -s EXPORTED_RUNTIME_METHODS="['ccall','cwrap']"

SRCS = main.c board.c entities.c input.c

all: $(TARGET).js

$(TARGET).js: $(SRCS)
	$(CC) $(CFLAGS) $(WASM_FLAGS) -o $(TARGET).js $(SRCS)

clean:
	rm -f $(TARGET).js $(TARGET).wasm

.PHONY: all clean
