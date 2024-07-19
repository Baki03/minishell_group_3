/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:51:18 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 15:51:40 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	*get_env_var_name(t_env *env, char *name)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (ft_strncmp(var->name, name, ft_strlen(name)))
		{
			return (var->name);
		}
		var = var->next;
	}
	return (NULL);
}