/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:43:11 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 15:43:16 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int	is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (is_double_quote(c) || is_single_quote(c))
		return (1);
	return (0);
}