/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:11:32 by johassin          #+#    #+#             */
/*   Updated: 2024/06/20 12:11:56 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstfirst(t_list *list)
{
	while (list)
	{
		if (!list->prev)
			return (list);
		list = list->prev;
	}
	return (list);
}
