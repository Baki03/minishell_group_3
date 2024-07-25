/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_replace_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:24:22 by rpepi             #+#    #+#             */
/*   Updated: 2024/07/25 15:14:43 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	check_if_var(t_env *env, char *name)
{
	t_var	*curr_var;

	curr_var = env->first_var;
	while (curr_var->next)
	{
		if (ft_strncmp(curr_var->name, name, ft_strlen(name)))
			return (1);
		curr_var = curr_var->next;
	}
	return (0);
}

static char	*split_and_write(char *content, char *value, int start, int end)
{
	char	*first_part;
	char	*second_part;
	char	*new_content;

	first_part = ft_malloc_substrcpy(content, 0, start - 1);
	second_part = ft_malloc_substrcpy(content, end + 1, ft_strlen(content));
	new_content = ft_strjoin_inter_str(first_part, second_part, value);
	free(value);
	free(first_part);
	free(second_part);
	return (new_content);
}

int	replace_var(t_env *env, char *content, int start, int end)
{
	t_var	*curr_var;
	char	*value;
	char	*tmp_content;
	int		new_index;
	char	*name;

	name = ft_malloc_substrcpy(content, start, end);
	curr_var = env->first_var;
	tmp_content = ft_malloc_strcpy(content);
	while (curr_var->next)
	{
		if (ft_strncmp(curr_var->name, name, ft_strlen(name)))
			break ;
		curr_var = curr_var->next;
	}
	value = ft_malloc_strcpy(curr_var->value);
	content = split_and_write(tmp_content, value, start, end);
	new_index = start - 1 + ft_strlen(value);
	free(value);
	free(name);
	free(tmp_content);
	return (new_index);
}

int	find_dollar_word(t_env *env, char *content, int end)
{
	int		start;
	int		i;
	char	*name;
	int		new_index;

	new_index = 0;
	start = 0;
	i = end;
	while (i > 0)
	{
		if (content[i] == '$')
			start = i;
		i--;
	}
	name = ft_malloc_substrcpy(content, start, end);
	if (!name)
		return (0);
	if (check_if_var(env, name))
		new_index = replace_var(env, content, start, end);
	free(name);
	return (new_index);
}
