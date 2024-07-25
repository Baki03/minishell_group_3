NAME                = minishell

LIBFT               = ./libft/libft.a
INC_DIR             = src/inc/
SRC_DIR             = src/
OBJ_DIR             = obj/

CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra -I $(INC_DIR)
RM                  = rm -f

COMMANDS_SRC        = main.c \
                      parsing/delete_content.c \
                      parsing/detection.c \
                      parsing/find_replace_arg.c \
                      parsing/find_type_arg.c \
                      parsing/get.c \
                      parsing/init_class.c \
                      parsing/token/chain_tokens.c \
                      parsing/token/connect.c \
                      parsing/token/file_tokenizer.c \
                      parsing/token/tokenize_arg.c \
                      parsing/token/tokenize_cmd.c \
                      parsing/token/tokenize_redir.c \
                      parsing/token/tokenizer.c \
                      parsing/is/is_bins.c \
                      parsing/is/is_cmd.c \
                      parsing/is/is_dollar_word.c \
                      parsing/is/is_file.c \
                      parsing/is/is_flag.c \
                      parsing/is/is_in.c \
                      parsing/is/is_metachar.c \
                      parsing/is/is_pipe.c \
                      parsing/is/is_quote.c \
                      parsing/is/is_redir.c \
                      parsing/is/is_separator.c \
                      parsing/is/is_spaces.c \
                      parsing/is/is_variable.c \
                      parsing/is/is_word.c \
                      libft_utils/free_utils.c \
                      libft_utils/malloc_utils.c \
                      libft_utils/utils.c \
                      init_env/init_env.c \
                      init_env/create_chained_env.c

SRCS                = $(addprefix $(SRC_DIR), $(COMMANDS_SRC))
OBJS                = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRCS))

all:                $(NAME)

$(LIBFT):
	@make -C ./libft

$(OBJ_DIR)/%.o:     $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):            $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean:             clean
	@$(RM) $(NAME)
	@make fclean -C ./libft

re:                 fclean all

.PHONY:             all clean fclean re
