/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:34:28 by pepi              #+#    #+#             */
/*   Updated: 2024/07/22 14:05:22 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	tokenize_line(t_env *env, char *line)
{
	int index;

	index = 0;
	while (line[index])
	{
		if (is_string(env, line, index))
		{
			index = class_string(env, line, index);
		}
		if (is_redir(env, line, index))
		{
			index = class_redir(env, line, index);
		}
		index++;
	}
}

int	is_string(t_env *env, char *line, int i)
{
	int	ret;

	ret = 0;
	if (!is_separator(line, i)) || (!is_redir(line, i)) 
		ret = 1;
	return (ret);
}

int	class_string(t_env *env, char	*line, int index)
{
	char	*content;
	int		new_index;
	t_token	*token;

	new_index = string_detection(env, line, index);
	content = ft_malloc_substrcpy(line, index, new_index);
	if (is_cmd(env, content))
	{
		tokenize_cmd(env, content);
	}
	else
	{
		tokenize_arg(env, content);
	}
	return (new_index);	
}
