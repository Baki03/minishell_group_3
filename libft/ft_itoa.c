/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:17:34 by johassin          #+#    #+#             */
/*   Updated: 2023/10/17 14:31:26 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_char(int n)
{
	int			i;
	long int	nb;
	int			minus;

	minus = 0;
	nb = n;
	i = 0;
	if (nb < 0)
	{
		minus = 1;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i + minus);
}

char	*ft_itoa(int n)
{
	char		*rtn;
	long int	nb;
	int			nb_char;

	nb = n;
	nb_char = ft_nb_char(n);
	rtn = malloc(sizeof(char) * nb_char + 1);
	if (!rtn)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	rtn[nb_char] = '\0';
	while (nb_char)
	{
		nb_char--;
		rtn[nb_char] = nb % 10 + '0';
		nb /= 10;
		if (nb_char == 0 && n < 0)
			rtn[nb_char] = '-';
	}
	return (rtn);
}
