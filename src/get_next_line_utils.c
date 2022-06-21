/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:57:31 by hohayrap          #+#    #+#             */
/*   Updated: 2022/06/17 19:40:00 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
		++index;
	return (index);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char		*new_str;
	size_t		f_index;
	size_t		s_index;

	new_str = malloc(sizeof (char)
			* (ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	f_index = 0;
	s_index = 0;
	if (s1)
		while (s1[f_index])
			new_str[s_index++] = s1[f_index++];
	f_index = 0;
	if (s2)
		while (s2[f_index])
			new_str[s_index++] = s2[f_index++];
	new_str[s_index] = '\0';
	free(s1);
	return (new_str);
}

int	ft_gnl_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		++index;
	}
	return (0);
}
