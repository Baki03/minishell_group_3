/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:03 by johassin          #+#    #+#             */
/*   Updated: 2024/06/20 11:41:40 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (list)
	{
		if (*list)
		{
			last = ft_lstlast(*list);
			last->next = new;
			new->prev = last;
		}
		else
			*list = new;
	}
}
