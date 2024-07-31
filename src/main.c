/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:48:31 by pepi              #+#    #+#             */
/*   Updated: 2024/07/31 10:34:30 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	*prompt(void)
{
	char	*input;

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
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**env_tab;
	char	*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = prompt();
		if (!input)
			return (EXIT_FAILURE);
		if (!check_open_quotes(input))
		{
			free(input);
			return (EXIT_FAILURE);
		}
		env_tab = ft_malloc_strcpy_array(envp);
		env = init_env(env_tab);
		tokenize_line(env, input);
		if (env->error_in_parsing == 1)
		{
			return (ft_free(input, env, env->first_token), 1);
			printf("error");
		}
		else
			printf("zeb");
		free(input);
		return (0);
	}
}
