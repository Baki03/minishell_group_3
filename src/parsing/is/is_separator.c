/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:28 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_separator(char *line, int i)
{
	if (!line[i])
		return (0);
	if (is_redirection(line, i) || is_spaces(line, i))
		return (1);
	return (0);
}

int	is_delimiter(t_env *env, char *line, int index)
{
	if (is_spaces(line[index]) || is_separator(line, index)
		|| is_variable(env, line, index))
		return (1);
	return (0);
}

int	is_variable_delimiter(char *line, int index)
{
	if (is_separator(line, index)
		|| line[index] == '$' || line[index] == '\0'
		|| is_quote(line[index]))
		return (1);
	return (0);
}
