/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:38:44 by johassin          #+#    #+#             */
/*   Updated: 2023/11/03 12:38:35 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;

	src2 = src;
	dst2 = dst;
	if (dst == 0 && dst == src)
		return (dst);
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
