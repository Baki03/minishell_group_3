/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:21 by johassin          #+#    #+#             */
/*   Updated: 2024/06/18 15:46:17 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	char	*rtn;
	size_t	i;

	i = 0;
	if (n <= 0)
		return (NULL);
	while (str[i])
		i++;
	if (i < n)
	{
		rtn = malloc(sizeof(char) * i + 1);
		if (!rtn)
			return (NULL);
	}
	i = -1;
	rtn = malloc(sizeof(char) * n + 1);
	if (!rtn)
		return (NULL);
	while (++i < n)
		rtn[i] = str[i];
	rtn[i] = '\0';
	return (rtn);
}
