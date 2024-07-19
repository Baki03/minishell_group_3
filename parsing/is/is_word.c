/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:42:42 by pepi              #+#    #+#             */
/*   Updated: 2024/07/19 17:56:17 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int is_word(char    *content)
{
    int i;

    i = 0;
    if ((is_in_quotes(content)) || (is_file(content))
        || (is_dollar_word(content)) || (is_flag(content)))
        return (0);
    while (content[i])
    {
        if (is_redir(content, i))
            return (0);
        i++;
    }
    return (1);
}
