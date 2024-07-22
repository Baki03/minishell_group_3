/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dollar_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:07:09 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/22 16:34:26 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_dollar_word(char	*content)
{
	int i;

	i = 0;
	if (!content)
		return (0);
	if (content[i] == '$')
	{
		i++;
		while (content[i])
		{
			if (content[i] == '$')
				return (0);
			i++;
		}
		return (1);
	}
	return (1);
}

int contain_dollar_word(char	*content)
{
	int i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '$')
		{
			i++;
			if (is_spaces(content[i]) || is_meta_char(content[i]) || (is_double_quote()))
					return (0);
			while (content[i])
			{
				if (content[i] == '$')
				{
					content = delete_content(content);
					return(0);
				}
				if (is_spaces(content[i]) || is_meta_char(content[i]))
					return (1);
				i++;
			}
		}
	}
}

void	check_variable(char *content)
{
	if (is_in_double_quote(content))
	{
		
	}
}
