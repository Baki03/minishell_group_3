/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:51:15 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 16:51:22 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}

void	connect_var(t_var *curr_var, t_var *next_var)
{
	curr_var->next = next_var;
	next_var->prev = curr_var;
}

void	connect_arg(t_arg *curr_arg, t_arg *next_arg)
{
	curr_arg->next = next_arg;
	next_arg->prev = curr_arg;
}