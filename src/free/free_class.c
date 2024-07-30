/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:01:17 by pepi              #+#    #+#             */
/*   Updated: 2024/07/30 13:39:50 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_file(t_file *file)
{
	if (file)
	{
		if (file->name)
		{
			free(file->name);
		}
		free(file);
	}
}

void	free_flags(t_flags *flags)
{
	if (flags)
	{
		if (flags->content)
		{
			free(flags->content);
		}
		free(flags);
	}
}

void	free_redir(t_redir *redir)
{
	if (redir)
	{
		if (redir->limiter)
		{
			free(redir->limiter);
		}
		if (redir->tmp_file)
		{
			free_file(redir->tmp_file);
		}
		if (redir->content)
		{
			free(redir->content);
		}
		free(redir);
	}
}

void	free_string(t_string *string)
{
	if (string)
	{
		if (string->content)
		{
			free(string->content);
		}
		free(string);
	}
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->content)
			free(cmd->content);
		free(cmd);
	}
}

