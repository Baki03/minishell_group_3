/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:28:40 by pepi              #+#    #+#             */
/*   Updated: 2024/07/22 14:36:28 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARE_H
# define DECLARE_H

# include "minishell.h" 

/* main */

int     main(int argc, char **argv, char    **envp);
void	*prompt(t_env    *env, char *input);

/*libft utils*/

void	free_dtab(char **tab);
char	*ft_malloc_substrcpy(char *origin, int start, int end);
char	*ft_malloc_strcpy(char *origin);
char	**ft_malloc_strcpy_array(char **origin);

/*init env*/

t_env	*init_env(char **env_tab);
t_var   *init_variable(char	*name, char	*value, int id);
void	connect_var(t_var *curr_var, t_var *next_var);

/*parsing*/

t_token	*init_token(void);
t_word	*init_word(char *content, int id);
t_cmd	*init_cmd(char *content, int id);




#endif 