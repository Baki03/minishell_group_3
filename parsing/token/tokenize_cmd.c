/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:57:22 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 16:52:57 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int find_type_cmd(t_env *env, char  *content)
{
    if (is_bin(env, content))
        return (8);  
    if (is_built_in(content))
		return (7);
    return (0);
}

void tokenize_cmd(t_env *env, char	*content)
{
	int		type;
	t_token	*token;
	
	if (!content)
	{
		env->error_in_parsing = 1;
		return ;
	}
	type = find_type_cmd(env, content);
	token = init_token();
	token->id = type;
	token->class = init_cmd(content, type);
	add_token_list(env, token);
}