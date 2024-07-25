/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:56:02 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_in_double_quote(char *content)
{
	int	i;

	i = 0;
	if (is_double_quote(content[i]))
	{
		while (content[i])
			i++;
		if (is_double_quote(content[i - 1]))
			return (1);
	}
	return (0);
}

int	is_in_single_quote(char *content)
{
	int	i;

	i = 0;
	if (is_single_quote(content[i]))
	{
		while (content[i])
			i++;
		if (is_single_quote(content[i - 1]))
			return (1);
	}
	return (0);
}

int	is_in_quotes(char *content)
{
	if (is_in_double_quote(content) || is_in_single_quote(content))
		return (1);
	return (0);
}
