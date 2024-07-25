/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:46 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/25 15:09:28 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	extract_new_content(char *content,
	char *new_content, int start, int end)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	while (content[i] && i < start)
	{
		new_content[j] = content[i];
		i++;
		j++;
	}
	i = end;
	while (content[i])
	{
		new_content[j] = content[i];
		i++;
		j++;
	}
	new_content[j] = '\0';
}

char	*delete_content(char *content)
{
	char	*new_content;
	int		i;
	int		start;
	int		end;

	i = 0;
	while (content[i])
	{
		if (content[i] == '$')
			break ;
		i++;
	}
	start = i;
	while (content[i])
	{
		if (is_spaces(content[i]) || is_metachar(content[i]))
			end = i;
		i++;
	}
	new_content = malloc(sizeof(char *) * (ft_strlen(content - (end - start
						+ 1))));
	if (!new_content)
		return (NULL);
	extract_new_content(content, new_content, start, end);
	free(content);
	return (new_content);
}
