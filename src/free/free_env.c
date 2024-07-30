/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:05 by pepi              #+#    #+#             */
/*   Updated: 2024/07/30 13:39:55 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

void	free_var(t_var *var)
{
	t_var	*temp;

	while (var)
	{
		temp = var;
		var = var->next;
		if (temp->name)
			free(temp->name);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}

void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (env)
	{
		if (env->env_variable)
		{
			while (env->env_variable[i] != NULL)
				free(env->env_variable[i]);
			free(env->env_variable);
		}
		if (env->first_var)
			free_var(env->first_var);
		free(env);
	}
}

void	ft_free(char *input, t_env *env, t_token *token)
{
	free_tokens(token);
	free_env(env);
	free(input);
}
