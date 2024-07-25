/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:15:52 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 12:54:56 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_flag(char *content)
{
	int	i;

	i = 0;
	if (content[i] != '-')
		return (0);
	if ((content[i] == '-' && is_letter(content[i + 1]))
		&& (is_letter(content[i + 2]) || content[i + 2] == '\0'))
	{
		return (1);
	}
	else
		return (0);
}
