/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:55:28 by johassin          #+#    #+#             */
/*   Updated: 2023/10/17 17:13:49 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	if (set == NULL)
		return (0);
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i++;
	}
	return (ft_strlen(s1));
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	if (set == NULL)
		return (i);
	if (i == 0)
		return (0);
	while (s1[--i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i + 1);
	}
	return (ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	rtn = malloc(sizeof(char) * (end - start) + 1);
	if (!rtn)
		return (NULL);
	while (start + i < end)
	{
		rtn[i] = s1[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
