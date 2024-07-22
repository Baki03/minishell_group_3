/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:44:57 by johassin          #+#    #+#             */
/*   Updated: 2023/10/18 12:38:20 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	rtn_size;

	rtn_size = 0;
	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (dst[rtn_size] && rtn_size < dstsize)
		rtn_size++;
	while (src[i] && dstsize && rtn_size + i < dstsize - 1)
	{
		dst[rtn_size + i] = src[i];
		i++;
	}
	if (rtn_size < dstsize)
		dst[rtn_size + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (rtn_size + i);
}
