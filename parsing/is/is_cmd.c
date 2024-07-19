/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:46:36 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 16:08:23 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_built_in(char *content)
{
	if (ft_strncmp(content, "echo", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "cd", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "pwd", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "env", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "export", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "unset", ft_strlen(content)))
		return (1);
	if (ft_strncmp(content, "exit", ft_strlen(content)))
		return (1);
	return (0);
}

int	is_bin(t_env *env, char *word)
{
	char	**bins;

	bins = get_env_bins(env);
	if (!bins)
		return (0);
	else if (test_absolute_bin_access(word) || test_bin_access(bins, word))
	{
		free_darray(bins);
		return (1);
	}
	free_darray(bins);
	return (0);
}


int	is_cmd(t_env *env, char *word)
{
	if (is_bin(env, word) || is_built_in(word))
    {
        free(word);
		return (1);
    }
    free(word);
	return (0);
}