#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johassin <johassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 13:09:49 by pepi              #+#    #+#              #
#    Updated: 2024/07/31 15:13:41 by johassin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 	minishell

SRC	= 	src/main.c \
		src/free/free_class.c \
        src/free/free_env.c \
        src/check_input.c \
		src/parsing/delete_content.c \
        src/parsing/detection.c \
        src/parsing/find_replace_arg.c \
        src/parsing/find_type_arg.c \
        src/parsing/get.c \
        src/parsing/init_class.c \
        src/parsing/token/chain_tokens.c \
		src/parsing/token/connect.c \
        src/parsing/token/file_tokenizer.c \
        src/parsing/token/tokenize_arg.c \
        src/parsing/token/tokenize_cmd.c \
    	src/parsing/token/tokenize_redir.c \
		src/parsing/token/tokenizer.c \
        src/parsing/is/is_bins.c \
        src/parsing/is/is_cmd.c \
        src/parsing/is/is_token_basic_redir.c \
    	src/parsing/is/is_dollar_word.c \
		src/parsing/is/is_file.c \
        src/parsing/is/is_flag.c \
        src/parsing/is/is_in.c \
        src/parsing/is/is_metachar.c \
        src/parsing/is/is_pipe.c \
        src/parsing/is/is_quote.c \
        src/parsing/is/is_redir.c \
        src/parsing/is/is_separator.c \
        src/parsing/is/is_spaces.c \
        src/parsing/is/is_variable.c \
        src/parsing/is/is_word.c \
        src/libft_utils/free_utils.c \
        src/libft_utils/malloc_utils.c \
        src/libft_utils/utils.c \
    	src/libft_utils/utils_2.c \
        src/init_env/init_env.c \
        src/init_env/create_chained_env.c

OBJ = $(SRC:.c=.o)
LIBFT	= ./libft
LIBFT_A = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) -lreadline

clean:
	@make -C $(LIBFT) fclean
	rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re