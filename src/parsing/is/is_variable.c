/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:49:32 by pepi              #+#    #+#             */
/*   Updated: 2024/07/29 16:04:30 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_variable_word(char *line, int i)
{
	if (line[i] == '$' && !(is_spaces(line[i + 1]))
		&& line[i + 1] != '\0' && !(is_quote(line[i + 1]))
		&& !(is_separator(line, i + 1)))
		return (1);
	return (0);
}

int	variable_exist(t_env *env, char *name)
{
	int	i;

	i = get_env_var_name(env, name);
	if (i <= 0)
		return (0);
	return (1);
}

char	*variable_name_extraction(char *line, int index)
{
	int		start;
	int		end;
	char	*name;

	end = index;
	start = index;
	if (line[index] == '$')
		return (NULL);
	index++;
	while (line[index])
	{
		if (is_variable_delimiter(line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (is_variable_delimiter(line, index))
		end = index - 1;
	name = ft_malloc_substrcpy(line, start, end);
	return (name);
}

int	is_variable(t_env *env, char *line, int i)
{
	char	*name;

	if (is_variable_word(line, i))
	{
		name = variable_name_extraction(line, ++i);
		if (!name)
			return (0);
		if (variable_exist(env, name))
		{
			free(name);
			return (1);
		}
		free(name);
	}
	return (0);
}
