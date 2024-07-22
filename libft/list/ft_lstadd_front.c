/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johassin < johassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:33:06 by johassin          #+#    #+#             */
/*   Updated: 2024/06/19 13:23:01 by johassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*temp;

	temp = *list;
	if (list)
	{
		if (*list)
		{
			new->next = *list;
			temp->prev = new;
		}
		*list = new;
	}
}
