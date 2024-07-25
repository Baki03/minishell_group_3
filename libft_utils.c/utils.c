/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:35:09 by pepi              #+#    #+#             */
/*   Updated: 2024/07/25 13:05:04 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_inter(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	str = malloc(sizeof(char) * (i + j + 2));
	if (!str)
		return (NULL);
	while (i--)
		str[k++] = *s1++;
	str[k++] = c;
	while (j--)
		str[k++] = *s2++;
	str[k] = '\0';
	return (str);
}

static char	*ft_strjoin_inter_str_code(char const *s1, char const *s2,
		char *content, int i)
{
	char	*str;
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(str)
				+ 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[l++] = s1[i++];
	while (content[j])
		str[l++] = content[i++];
	while (s2[k])
		str[l++] = s2[k++];
	str[l] = '\0';
	return (str);
}

char	*ft_strjoin_inter_str(char const *s1, char const *s2, char *content)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin_inter_str_code(s1, s2, content, i);
	return (str);
}

int	ft_ismaj(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_letter(char c)
{
	if (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122) return (1);
	return (0);
}
