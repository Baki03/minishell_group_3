/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:49:49 by pepi              #+#    #+#             */
/*   Updated: 2024/07/19 16:42:32 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int check_variable(t_env *env, char *content)
{
	int i;
	
	i = 0;
	if (is_in_single_quote(content))
		return (0);
	while (content[i])
	{
		if (is_var(content[i]))
		{
			echange_var(env, content, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void    tokenize_arg(t_env *env, char *content)
{
	int     type;
	t_token	*token;
	
	if (!content)
	{
		env->error_in_parsing = 1;
		return ;
	}
	type = find_type_arg(env, content);
	token = init_token();
	token->id = type;
	token->class = init_cmd(content, type);
	add_token_list(env, token);
}
