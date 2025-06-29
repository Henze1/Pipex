CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = pipex

LIBFT = libft
LIBFT_NAME = libft.a

PRINTF = ft_printf
PRINTF_NAME = libftprintf.a

OBJ_DIR = build/objects
OUTPUT_DIR = build/outputs

SRC = main.c \
		service/pipex.c \
		service/pipex_utils.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PRINTF)
	mkdir -p $(OUTPUT_DIR)
	cp $(LIBFT)/$(LIBFT_NAME) $(OUTPUT_DIR)/
	cp $(PRINTF)/$(PRINTF_NAME) $(OUTPUT_DIR)/
	make fclean	-C $(LIBFT)
	make fclean	-C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(OUTPUT_DIR)/$(LIBFT_NAME) $(OUTPUT_DIR)/$(PRINTF_NAME) -o $(OUTPUT_DIR)/$(NAME)

$(OBJ_DIR)/%.o: %.c headers/pipex.h Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	rm -f $(OUTPUT_DIR)/$(LIBFT_NAME)
	rm -f $(OUTPUT_DIR)/$(PRINTF_NAME)

re: fclean all

.PHONY: all clean fclean re