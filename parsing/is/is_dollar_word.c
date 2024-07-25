/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dollar_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:07:09 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/25 15:13:33 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_dollar_word(char *content)
{
	int	i;

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

static int	contain_dollar_word_code(char *content)
{
	while (content[i])
	{
		if (content[i] == '$')
		{
			i++;
			if (is_spaces(content[i]) || is_meta_char(content[i])
				|| (is_double_quote()))
				return (i);
			while (content[i])
			{
				if (content[i] == '$')
				{
					content = delete_content(content);
					return (i + 1);
				}
				if (is_spaces(content[i]) || is_meta_char(content[i]))
				{
					find_dollar_word(content, i);
					return (i);
				}
				i++;
			}
		}
	}
}

int	contain_dollar_word(char *content)
{
	int	i;

	i = 0;
	return (contain_dollar_word_code(content, i));
}
