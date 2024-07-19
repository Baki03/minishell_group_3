/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:43:05 by pepi              #+#    #+#             */
/*   Updated: 2024/07/19 17:42:10 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int find_type_arg(t_env *env, char  *content)
{
    if (is_in_double_quote(content))
    {
        check_variable(content);
        return (4);
    }
    if (is_in_single_quote(content))
        return (3);
    if (is_flag(content))
        return (9);
    if (is_file(content))
        return (12);
    if (is_dollar_word(content))
    {
        check_variable(content);
        return (11);
    }
    if (is_word(content))
        return (2);
    return (0);
}
