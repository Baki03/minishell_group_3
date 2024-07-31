/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:34:28 by pepi              #+#    #+#             */
/*   Updated: 2024/07/31 10:39:55 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_string(char *line, int i)
{
	int	ret;

	ret = 0;
	if (!is_separator(line, i))
		ret = 1;
	return (ret);
}

static int	class_string(t_env *env, char *line, int index)
{
	char	*content;
	int		new_index;

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

void	tokenize_line(t_env *env, char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (is_string(line, index))
		{
			index = class_string(env, line, index);
		}
		if (is_redir(line, index))
		{
			index = class_redir(env, line, index);
		}
		index++;
	}
}
