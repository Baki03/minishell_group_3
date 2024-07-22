/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:29:11 by johassin          #+#    #+#             */
/*   Updated: 2023/11/03 13:13:43 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_space(size_t *i, int *minus, const char *str)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*minus = -1;
		*i += 1;
	}
}

static void	ft_get_li_of(long long int *li, long long int *of, int minus)
{
	if (minus == -1)
		*of = LLONG_MIN + LLONG_MAX + LLONG_MAX;
	else
		*of = LLONG_MAX;
	*li = *of % 10;
	*of /= 10;
}

int	ft_atoi(const char *str)
{
	long long int	rtn;
	size_t			i;
	int				minus;
	long long int	li;
	long long int	of;

	i = 0;
	minus = 1;
	rtn = 0;
	ft_skip_space(&i, &minus, str);
	ft_get_li_of(&li, &of, minus);
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn = rtn * 10 + str[i] - '0';
		i++;
		if (minus == -1 && (rtn > of || (rtn == of && str[i] > li)))
			return (0);
		if (minus == 1 && (rtn > of || (rtn == of && str[i] > li)))
			return (-1);
	}
	return ((int)rtn * minus);
}
