/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:33 by pepi              #+#    #+#             */
/*   Updated: 2024/07/29 15:51:47 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_pipe(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '|' && line[i + 1] != '|')
		return (1);
	return (0);
}

int	is_redir(char *line, int i)
{
	if (!line[i])
		return (0);
	if (is_pipe(line, i) || is_output_chevrons(line, i)
		|| is_input_chevrons(line, i) || is_append_chevrons(line, i)
		|| is_heredoc(line, i))
		return (1);
	return (0);
}

int	is_file_redirection(char *line, int i)
{
	if (is_output_chevrons(line, i) || is_input_chevrons(line, i)
		|| is_append_chevrons(line, i))
		return (1);
	return (0);
}
