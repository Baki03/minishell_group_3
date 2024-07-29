/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:48:31 by pepi              #+#    #+#             */
/*   Updated: 2024/07/26 16:50:07 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

static void	*prompt(char *input)
{
	while (1)
	{
		input = readline("\033[1;32mminishell $ \033[0m");
		if (!input)
		{
			printf("exit\n");
			return (NULL);
		}
		if (input[0] == '\0')
		{
			add_history(input);
		}
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

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**env_tab;
	char	*input;

	(void)argc;
	(void)argv;
	input = NULL;
	prompt(input);
	if (!input)
		return (EXIT_FAILURE);
	if (!check_input(input))
	{
		free(input);
		return (EXIT_FAILURE);
	}
	env_tab = ft_malloc_strcpy_array(envp);
	env = init_env(env_tab);
	tokenize_line(env, input);
	if (env->error_in_parsing == 1)
		free(input);
	free_tokens(env->first_token);
	free_env(env);
	return (0);
}
