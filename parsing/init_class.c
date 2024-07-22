/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:49:53 by pepi              #+#    #+#             */
/*   Updated: 2024/07/22 14:36:23 by rpepi            ###   ########.fr       */
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

t_word	*init_word(char *content, int id)
{
	t_word	*word;

	word = (t_word *)malloc(sizeof(t_word));
	if (!word)
		return (NULL);
	word->content = content;
	word->id = id;
	return (word);
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