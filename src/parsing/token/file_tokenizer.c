/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:13:38 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 15:27:37 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*create_token_file(char *name, int fd, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_file(name, fd);
	return (token);
}

t_token	*file_tokenizer(char *name, int id)
{
	t_token	*token;
	int		fd;

	fd = open(name, O_RDONLY | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		printf("%s : so such file or directory\n", name);
	token = create_token_file(name, fd, id);
	return (token);
}

int	next_file_tokenizer(t_env *env, char *line, int index)
{
	t_token	*token;
	int		new_index;
	char	*content;

	if (line[index] == '\0')
		return (index);
	index = spaces_escape(line, index);
	new_index = file_detection(line, index);
	content = ft_malloc_substrcpy(line, index, new_index);
	token = file_tokenizer(content, TOKEN_FILE);
	add_token_list(env, token);
	return (new_index);
}

int	arg_redirect_extraction(t_env *env, t_token *token, char *line, int index)
{
	if (is_token_basic_redirection(token))
	{
		index = next_file_tokenizer(env, line, ++index);
	}
	return (index);
}
