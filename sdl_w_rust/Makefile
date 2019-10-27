#
# Makefile for the project
#
PROJECT_NAME=sdl_bitmap_and_mouse

# Location of the source code
SRC_DIR=src/

# Includes
INCLUDES= -I. \
          -I/usr/include

# SDL Libraries
SDL_LIBS=`sdl2-config --libs`

# Standard Libraries
LIBS= ${SDL_LIBS} \
      -lSDL2_ttf \
      -L/usr/lib

# Flags
CFLAGS = -std=gnu18 \
         -O2 \
         -fpic \
         -Wall \
         -Wextra \
         -Wpedantic \
         -Wno-missing-braces

# Compiler
CC = cc -g

# Headers
HDR = $(SRC_DIR)main.h \
      $(SRC_DIR)assetloader.h \
      $(SRC_DIR)level.h \
      $(SRC_DIR)camera.h \
      $(SRC_DIR)csv.h \
      $(SRC_DIR)game.h \
      $(SRC_DIR)font.h \
      $(SRC_DIR)size.h \
      $(SRC_DIR)sdl_funcs.h \
      $(SRC_DIR)globals.h

# C sources
SRC = $(SRC_DIR)main.c \
      $(SRC_DIR)assetloader.c \
      $(SRC_DIR)level.c \
      $(SRC_DIR)sdl_funcs.c \
      $(SRC_DIR)camera.c \
      $(SRC_DIR)csv.c \
      $(SRC_DIR)game.c \
      $(SRC_DIR)font.c \
      $(SRC_DIR)sdl_funcs.c \
      $(SRC_DIR)globals.c

# C objects
OBJ = ${SRC:.c=.o}


#
# Makefile options
#


# State the "phony" targets
.PHONY: all clean


all: clean ${PROJECT_NAME}

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${PROJECT_NAME}: ${OBJ}
	@echo ${CC} ${CFLAGS} ${INCLUDES} -o $@ ${LIBS} $^
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ ${LIBS} $^

clean:
	@echo "Cleaning away old build..."
	@rm -f ${PROJECT_NAME} $(SRC_DIR)*.o
