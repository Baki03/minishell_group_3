/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:37:39 by johassin          #+#    #+#             */
/*   Updated: 2023/11/03 13:37:13 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_string(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_malloc_and_copy(const char *s, int *cursor, char c)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	while (s[*cursor + i] == c)
		*cursor += 1;
	while (s[*cursor + i] != c && s[*cursor + i])
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (NULL);
	while (j < i)
	{
		rtn[j] = s[*cursor + j];
		j++;
	}
	*cursor += j;
	rtn[j] = '\0';
	return (rtn);
}

static char	**ft_free_array(char **array, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		cursor;
	int		nb_string;
	int		i;

	i = 0;
	cursor = 0;
	if (!s)
		return (NULL);
	nb_string = ft_nb_string(s, c);
	array = malloc(sizeof(char *) * (nb_string + 1));
	if (!array)
		return (NULL);
	while (i < nb_string)
	{
		array[i] = ft_malloc_and_copy(s, &cursor, c);
		if (!array[i])
			return (ft_free_array(array, i));
		i++;
	}
	array[i] = NULL;
	return (array);
}
