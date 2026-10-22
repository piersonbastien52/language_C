CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99 -fstack-protector -Iinlcude

SRC =     Project/export /export.c \
        Project/Representation/library/apply_style.c \
        Project/Representation/library/ask_for_a_flint.c \
        Project/Representation/library/color.c \
        Project/Representation/library/Points.c \
        Project/Representation/generation.c \
        Project/All_shapes.c \
        Project/project_CLI.c \

OBJ_DIR = bin
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

NAME = projet

vpath %.c src src/utils src/create_forme

build: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
    $(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(OBJ_DIR):
    mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR)
    rm -f $(NAME)


.PHONY: build clean