/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:21:43 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 12:36:34 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "declare.h"
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
# define TOKEN_WORD 2
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

#endif