/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:49:49 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 14:08:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_args_type(char *content, int type, t_token *token)
{
	int	fd;

	fd = 0;
	if (type == 4 || type == 3 || type == 2)
		token->class = init_word(content, type);
	if (type == 9)
		token->class = init_flags(content, type);
	if (type == 12)
	{
		fd = open(content, O_RDONLY | O_WRONLY | O_CREAT, 0777);
		if (fd < 0)
			printf("%s : so such file or directory\n", name);
		token->class = init_file(content, fd);
	}
}

void	tokenize_arg(t_env *env, char *content)
{
	int		type;
	t_token	*token;
	int		index;

	if (!content)
	{
		env->error_in_parsing = 1;
		return ;
	}
	index = 0;
	type = find_type_arg(env, content, index);
	token = init_token();
	token->id = type;
	init_args_type(content, type, token);
	add_token_list(env, token);
}
