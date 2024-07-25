/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:26:41 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_file(char *content)
{
	int	i;

	i = 0;
	if (is_in_quotes(content))
		return (0);
	while (content[i])
	{
		if (content[i] == '.')
		{
			if (content[i + 1] == '\0')
				return (0);
			while (content[i])
			{
				if (!is_letter(content[i]))
					return (0);
				i++;
			}
		}
		i++;
	}
	return (1);
}
