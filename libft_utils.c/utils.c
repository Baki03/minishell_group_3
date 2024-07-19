/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:35:09 by pepi              #+#    #+#             */
/*   Updated: 2024/07/17 15:35:17 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_inter(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	str = malloc(sizeof(char) * (i + j + 2));
	if (!str)
		return (NULL);
	while (i--)
		str[k++] = *s1++;
	str[k++] = c;
	while (j--)
		str[k++] = *s2++;
	str[k] = '\0';
	return (str);
}