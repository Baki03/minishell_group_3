/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:40:33 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/29 12:01:37 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	check_open_quotes(char *input)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (0);
	count = 0;
	while (input[i])
	{
		if (input[i] == '\"')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (0);
	return (1);
}

/*
int	check_input(char *input)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\\' || input[i] == ';')
			return (0);
		if (input[i] == '&' && input[i + 1] = )
		i++;
	}
	return (1);
}
*/
