/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:49:53 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 13:06:32 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->id = 0;
	token->class = NULL;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_string	*init_string(char *content, int id)
{
	t_string	*string;

	string = (t_string *)malloc(sizeof(t_string));
	if (!string)
		return (NULL);
	string->content = content;
	string->id = id;
	return (string);
}

t_cmd	*init_cmd(char *content, int id)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->id = id;
	cmd->content = content;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->pid = 0;
	return (cmd);
}

t_flags	*init_flags(char *content, int id)
{
	t_flags	*flag;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag->id = id;
	flag->content = content;
	return (flag);
}

t_file	*init_file(char *name, int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = name;
	file->fd = fd;
	return (file);
}
