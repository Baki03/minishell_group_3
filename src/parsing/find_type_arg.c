/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:43:05 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:58 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	replace_var_basic(t_env *env, char *content)
{
	t_var	*curr_var;
	char	*value;
	char	*tmp_content;
	int		start;

	start = 0;
	curr_var = env->first_var;
	tmp_content = ft_malloc_substrcpy(content, start + 1, ft_strlen(content));
	while (curr_var->next)
	{
		if (ft_strncmp(curr_var->name, content, ft_strlen(content)))
			break ;
		curr_var = curr_var->next;
	}
	if (!curr_var->next
		&& !ft_strncmp(curr_var->name, content, ft_strlen(content)))
	{
		free(tmp_content);
		return (0);
	}
	value = ft_malloc_strcpy(curr_var->value);
	content = value;
	free(value);
	free(tmp_content);
	return (1);
}

int	find_type_arg(t_env *env, char *content, int index)
{
	if (is_in_double_quote(content))
	{
		while (index < ft_strlen(content))
		{
			index = contain_dollar_word(content);
			find_dollar_word(env, content, index - 1);
		}
		return (4);
	}
	if (is_in_single_quote(content))
		return (3);
	if (is_flag(content))
		return (9);
	if (is_file(content))
		return (12);
	if (is_dollar_word(content))
	{
		if (!replace_var(env, content))
			return (0);
		return (2);
	}
	if (is_word(content))
		return (2);
	return (0);
}
