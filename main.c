/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:48:31 by pepi              #+#    #+#             */
/*   Updated: 2024/07/23 14:00:41 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*prompt(t_env *env, char *input)
{
	while (1)
	{
		input = readline("\033[1;32mminishell $ \033[0m");
		if (!input)
		{
			ft_printf("exit\n");
			return (NULL);
		}
		if (input[0] == '\0')
		{
			add_history(input);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**env_tab;
	char	*input;

	(void)argc;
	(void)argv;
	env_tab = ft_malloc_strcpy_array(envp);
	env = init_env(env_tab);
	prompt(env, input);
	if (!input)
		return (EXIT_FAILURE);
	tokenize_line(env, input);
	if (env->error_in_parsing == 1)
	{
		free(input);
		return (EXIT_FAILURE);
	}
	free(input);
	return (0);
}
