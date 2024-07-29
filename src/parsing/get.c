/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:51:18 by pepi              #+#    #+#             */
/*   Updated: 2024/07/29 16:06:27 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_var	*get_first_env_var(t_env *env)
{
	if (env->first_var)
		return (env->first_var);
	return (0);
}

char	*get_env_var_value(t_env *env, char *name)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (ft_strncmp(var->name, name, ft_strlen(name)))
		{
			return (var->value);
		}
		var = var->next;
	}
	return (NULL);
}

int	get_env_var_name(t_env *env, char *name)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (0);
	while (var)
	{
		if (ft_strncmp(var->name, name, ft_strlen(name)))
		{
			return (1);
		}
		var = var->next;
	}
	return (0);
}
