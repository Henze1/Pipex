CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT_NAME = libft.a
LIBFT_A = $(LIBFT_DIR)/$(LIBFT_NAME)

PRINTF_NAME = libftprintf.a
PRINTF_A = $(PRINTF_DIR)/$(PRINTF_NAME)

OBJ_DIR = build/objects
OUTPUT_DIR = build/outputs

NAME = $(OUTPUT_DIR)/pipex
LIBFT_OUTPUT = $(OUTPUT_DIR)/libft.a
PRINTF_OUTPUT = $(OUTPUT_DIR)/libftprintf.a

SRC = main.c \
		service/pipex.c \
		service/pipex_utils.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OUTPUT) $(PRINTF_OUTPUT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OUTPUT) $(PRINTF_OUTPUT) -o $(NAME)

$(LIBFT_OUTPUT): $(LIBFT_A)
	mkdir -p $(OUTPUT_DIR)
	cp $< $@

$(PRINTF_OUTPUT): $(PRINTF_A)
	mkdir -p $(OUTPUT_DIR)
	cp $< $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(PRINTF_A):
	make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c headers/pipex.h Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -rf $(OUTPUT_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re