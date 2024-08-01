/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin <johassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:48:31 by pepi              #+#    #+#             */
/*   Updated: 2024/08/01 12:44:42 by johassin         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

void print_tab(char **tab)
{
	int i = 0;

	while (tab[i])
		printf("%s\n", tab[i++]);
}
void print_var(t_env *env)
{
	t_var *var;
	t_var *temp;

	var = env->first_var;
	temp = var;
	while (temp)
	{
		printf("Name = %s\nvalue = %s\n", temp->name, temp->value);
		temp = temp->next;
	}
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
		// print_tab(env_tab);
		env = init_env(env_tab);
		// print_var(env);
		tokenize_line(env, input);
		if (env->error_in_parsing == 1)
		{
			return (ft_free(input, env, env->first_token), 1);
			printf("error\n");
		}
		else
			printf("parsing success\n");
		free(input);
	}
	return (0);
}
