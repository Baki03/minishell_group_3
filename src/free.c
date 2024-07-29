/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:01:17 by pepi              #+#    #+#             */
/*   Updated: 2024/07/26 16:50:43 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_file(t_file *file)
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

static void	free_flags(t_flags *flags)
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

static void	free_redir(t_redir *redir)
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

static void	free_string(t_string *string)
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

static void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->content)
			free(cmd->content);
		free(cmd);
	}
}

void	free_tokens(t_token *token)
{
	t_token	*temp;

	while (token)
	{
		temp = token;
		token = token->next;
		if (temp->class)
		{
			if (temp->id == 6)
				free_cmd((t_cmd *)temp->class);
			else if (temp->id == 12)
				free_file((t_file *)temp->class);
			else if (temp->id == 9)
				free_flags((t_flags *)temp->class);
			else if (temp->id == 2)
				free_string((t_string *)temp->class);
			else if (temp->id == 16)
				free_redir((t_redir *)temp->class);
		}
		free(temp);
	}
}
