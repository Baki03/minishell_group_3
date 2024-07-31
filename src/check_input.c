/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:40:33 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/31 10:30:11 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	check_open_quotes(char *input)
{
	int	i;
	int	single_quote_open;
	int	double_quote_open;

	single_quote_open = 0;
	double_quote_open = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && (i == 0 || input[i - 1] != '\\'))
			single_quote_open = !single_quote_open;
		else if (input[i] == '\"' && (i == 0 || input[i - 1] != '\\'))
			double_quote_open = !double_quote_open;
		i++;
	}
	if (single_quote_open || double_quote_open)
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
