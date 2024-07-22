/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:36:58 by johassin          #+#    #+#             */
/*   Updated: 2023/10/17 10:20:52 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (i--)
		str[k++] = *s1++;
	while (j--)
		str[k++] = *s2++;
	str[k] = '\0';
	return (str);
}
