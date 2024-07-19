/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:18:12 by pepi              #+#    #+#             */
/*   Updated: 2024/07/19 17:03:01 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	double_quotes_detection(char *line, int index)
{
	int	start;

	start = index;
	index++;
	while (line[index])
	{
		if (is_double_quote(line[index]))
			return (index);
		index++;
	}
	return (start);
}

int	single_quotes_detection(char *line, int index)
{
	int	start;

	start = index;
	index++;
	while (line[index])
	{
		if (is_single_quote(line[index]))
			return (index);
		index++;
	}
	return (start);
}

int	string_detection(t_env *env, char *line, int index)
{
	while (line[index])
	{
		if (is_delimiter(env, line, index))
		{
			return (index - 1);
		}
		if (is_double_quote(line[index]))
		{
			index = double_quotes_detection(line, index);
		}
		if (is_single_quote(line[index]))
		{
			index = single_quotes_detection(line, index);
		}
		index++;
	}
	return (index);
}