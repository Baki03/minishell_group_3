/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:21:43 by pepi              #+#    #+#             */
/*   Updated: 2024/07/26 16:48:17 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../../libft/libft.h"

# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define TOKEN_NULL 0
# define TOKEN_BLANK 1
# define TOKEN_STRING 2
# define TOKEN_SINGLE_QUOTE 3
# define TOKEN_DOUBLE_QUOTE 4
# define TOKEN_PARANTHESIS 5
# define TOKEN_COMMAND 6
# define TOKEN_BUILT_IN 7
# define TOKEN_BINARY 8
# define TOKEN_FLAGS 9
# define TOKEN_ARGUMENT 10
# define TOKEN_VARIABLE 11
# define TOKEN_FILE 12
# define TOKEN_REDIRECTION 16
# define TOKEN_PIPE 17
# define TOKEN_INPUT_CHEVRON 18
# define TOKEN_OUTPUT_CHEVRON 19
# define TOKEN_APPEND_CHEVRON 20
# define TOKEN_HERE_DOC 21
# define TOKEN_BOOLEAN 22
# define TOKEN_LIMITER 23

typedef struct s_token
{
	void			*class;
	int				id;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_cmd
{
	char			*content;
	int				id;
	int				fd_in;
	int				fd_out;
	pid_t			pid;
}					t_cmd;

typedef struct s_var
{
	int				index;
	int				id;
	char			*name;
	char			*value;
	struct s_var	*next;
	struct s_var	*prev;

}					t_var;

typedef struct s_env
{
	char			**env_variable;
	t_token			*first_token;
	t_var			*first_var;
	int				error_in_parsing;

}					t_env;

typedef struct s_file
{
	char			*name;
	int				fd;

}					t_file;

typedef struct s_string
{
	int				id;
	char			*content;

}					t_string;

typedef struct s_flags
{
	int				id;
	char			*content;

}					t_flags;

typedef struct s_redir
{
	int				fd_in;
	int				fd_out;
	int				type;
	char			*limiter;
	t_file			*tmp_file;
	char			*content;

}					t_redir;

/* main */
int			main(int argc, char **argv, char **envp);
int			check_input(char *input);

/*libft utils*/
void		free_dtab(char **tab);
char		*ft_malloc_substrcpy(char *origin, int start, int end);
char		*ft_malloc_strcpy(char *origin);
char		**ft_malloc_strcpy_array(char **origin);
char		*ft_strjoin_inter(char const *s1, char const *s2, char c);
char		*ft_strjoin_inter_str(char const *s1, char const *s2,
				char *content);
int			ft_ismaj(int c);
int			is_letter(char c);

/*init env*/
t_env		*init_env(char **env_tab);
t_var		*init_variable(char *name, char *value, int id);
void		connect_var(t_var *curr_var, t_var *next_var);
void		add_var(t_env *env, char **env_variable);
t_var		*add_variables_list(t_env *env, t_var *var);
char		*get_variable_name(char *variable);
char		*get_variable_name(char *variable);

/*parsing*/
t_token		*init_token(void);
t_string	*init_string(char *content, int id);
t_cmd		*init_cmd(char *content, int id);
void		extract_new_content(char *content, char *new_content, int start,
				int end);
char		*delete_content(char *content);
int			string_detection(t_env *env, char *line, int index);
int			find_dollar_word(t_env *env, char *content, int end);
int			find_type_arg(t_env *env, char *content, size_t index);
t_var		*get_first_env_var(t_env *env);
char		*get_env_var_value(t_env *env, char *name);
char		*get_env_var_name(t_env *env, char *name);
t_token		*init_token(void);
t_string	*init_string(char *content, int id);
t_cmd		*init_cmd(char *content, int id);
t_flags		*init_flags(char *content, int id);
t_file		*init_file(char *name, int fd);
int			replace_var(t_env *env, char *content, int start, int end);

/* tokenize */
void		tokenize_line(t_env *env, char *line);
int			class_redir(t_env *env, char *line, int index);
t_token		*create_token_redir(char *line, int index, int new_index);
int			redirection_detection(char *line, int index);
void		tokenize_cmd(t_env *env, char *content);
void		tokenize_arg(t_env *env, char *content);
void		add_token_list(t_env *env, t_token *token);
t_token		*create_token_file(char *name, int fd, int id);
t_token		*file_tokenizer(char *name, int id);
int			next_file_tokenizer(t_env *env, char *line, int index);
int			arg_redirect_extraction(t_env *env, t_token *token, char *line,
				int index);
void		connect_token(t_token *curr_token, t_token *next_token);
void		connect_var(t_var *curr_var, t_var *next_var);

/* is */
char		**get_env_bins(t_env *env);
int			test_bin_access(char **bins, char *word);
int			test_absolute_bin_access(char *path);
int			is_built_in(char *content);
int			is_bin(t_env *env, char *word);
int			is_cmd(t_env *env, char *word);
int			is_dollar_word(char *content);
int			contain_dollar_word(char *content);
int			is_file(char *content);
int			is_flag(char *content);
int			is_in_double_quote(char *content);
int			is_in_single_quote(char *content);
int			is_in_quotes(char *content);
int			is_metachar(char c);
int			is_pipe(char *line, int i);
int			is_redir(char *line, int i);
int			is_file_redirection(char *line, int i);
int			is_double_quote(char c);
int			is_single_quote(char c);
int			is_quote(char c);
int			is_output_chevrons(char *line, int i);
int			is_input_chevrons(char *line, int i);
int			is_append_chevrons(char *line, int i);
int			is_heredoc(char *line, int i);
int			is_separator(char *line, int i);
int			is_delimiter(t_env *env, char *line, int index);
int			is_variable_delimiter(char *line, int index);
int			is_spaces(char c);
int			spaces_escape(char *line, int index);
int			is_variable_word(char *line, int i);
int			variable_exist(t_env *env, char *name);
char		*variable_name_extraction(char *line, int index);
int			is_variable(t_env *env, char *line, int i);
int			is_word(char *content);

/* free */
void		free_tokens(t_token *token);
void		free_env(t_env *env);
void		free_var(t_var *var);
#endif