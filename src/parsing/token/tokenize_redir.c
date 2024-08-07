/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:09:00 by pepi              #+#    #+#             */
/*   Updated: 2024/07/31 10:57:13 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	redirection_detection(char *line, int index)
{
	int	start;

	start = index;
	while (line[index])
	{
		if (!(is_redir(line, index)))
		{
			return (index - 1);
		}
		index++;
	}
	return (start);
}

static int	type_of_redirect(char *content)
{
	if (is_pipe(content, 0))
		return (TOKEN_PIPE);
	else if (is_input_chevrons(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_input_chevrons(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_append_chevrons(content, 0))
		return (TOKEN_APPEND_CHEVRON);
	else if (is_output_chevrons(content, 0))
		return (TOKEN_OUTPUT_CHEVRON);
	else if (is_heredoc(content, 0))
		return (TOKEN_HERE_DOC);
	return (0);
}

static t_redir	*init_redirection(int type, char *content)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = NULL;
	redir->content = content;
	redir->tmp_file = NULL;
	return (redir);
}

t_token	*create_token_redir(char *line, int index, int new_index)
{
	char	*content;
	int		type;
	t_token	*token;

	content = ft_malloc_substrcpy(line, index, new_index);
	type = type_of_redirect(content);
	token = init_token();
	token->id = type;
	token->class = init_redirection(type, content);
	return (token);
}

int	class_redir(t_env *env, char *line, int index)
{
	t_token	*token;
	int		new_index;

	new_index = redirection_detection(line, index);
	token = create_token_redir(line, index, new_index);
	add_token_list(env, token);
	index = arg_redirect_extraction(env, token, line, new_index);
	return (index);
}
