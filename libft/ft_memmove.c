/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:01:51 by johassin          #+#    #+#             */
/*   Updated: 2023/11/03 12:38:15 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_temp;
	const char	*src_temp;

	dst_temp = dst;
	src_temp = src;
	if (dst_temp == 0 && dst == src)
		return (dst);
	if (src_temp <= dst_temp)
	{
		dst_temp += len - 1;
		src_temp += len - 1;
		while (len--)
			*dst_temp-- = *src_temp--;
	}
	else
		while (len--)
			*dst_temp++ = *src_temp++;
	return (dst);
}
