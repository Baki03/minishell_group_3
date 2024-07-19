/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:42:53 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 17:24:49 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*init_env(char **env_tab)
{
    t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->first_var = NULL;
	env->first_token = NULL;
    env->error_in_parsing = 0;
	add_var(env, env_tab);
    ft_free_dtab(env_tab);
	return (env);
}

t_var *init_variable(char	*name, char	*value, int id)
{
	t_var *var;

	var = malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->index = 0;
	var->id = id;
	var->name = name;
	var->value = value;
	var->next = NULL;
	var->prev = NULL;
	return (var);
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
