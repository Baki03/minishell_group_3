/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:47:50 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_token_list(t_env *env, t_token *token)
{
	t_token	*iter;

	if (!(env->first_token))
	{
		env->first_token = token;
	}
	else
	{
		iter = env->first_token;
		while (iter->next)
		{
			iter = iter->next;
		}
		connect_token(iter, token);
	}
}
