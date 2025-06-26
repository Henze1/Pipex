CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

LIBFT = libft
LIBFT_NAME = libft.a

#PRINTF = ft_printf
#PRINTF_NAME = ft_printf.a

OBJ_DIR = build/objects
OUTPUT_DIR = build/outputs

SRC = main.c \
		service/pipex.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	mkdir -p $(OUTPUT_DIR)
	cp $(LIBFT)/$(LIBFT_NAME) $(OUTPUT_DIR)/
	make fclean	-C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(OUTPUT_DIR)/$(LIBFT_NAME) -o $(OUTPUT_DIR)/$(NAME)

$(OBJ_DIR)/%.o: %.c headers/pipex.h Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	rm -f $(OUTPUT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re