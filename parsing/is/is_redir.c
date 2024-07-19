/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:41:15 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 15:42:14 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_output_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '>' && line[i + 1] != '>')
		return (1);
	return (0);
}

int	is_input_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '<' && line[i + 1] != '<')
		return (1);
	return (0);
}

int	is_append_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if ((line[i] == '>' && line[i + 1] == '>'))
		return (1);
	return (0);
}

int	is_heredoc(char *line, int i)
{
	if (!line[i])
		return (0);
	if ((line[i] == '<' && line[i + 1] == '<'))
		return (1);
	return (0);
}