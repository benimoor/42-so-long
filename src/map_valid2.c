/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:06:54 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/17 23:21:31 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top(char *top, int len)
{
	int	i;

	i = 0;
	while (top[i] == '1')
		i++;
	if (i != len)
		return (-1);
	return (0);
}

int	check_down(char *down, int len)
{
	int	i;

	i = 0;
	while (down[i] == '1')
		i++;
	if (i != len)
		return (-1);
	return (0);
}

int	check_middle(char **map, t_map *check, int i, int j)
{
	if (!(map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P'
		|| map[i][j] == 'E' || map[i][j] == 'C'))
		return (-1);
	if (map[i][j] == 'P')
	{
		if (check->player == 0)
			check->player = 1;
		else
			return (-1);
	}
	else if (map[i][j] == 'C')
	{
		if (check->coin < 1)
			check->coin += 1;
	}
	else if (map[i][j] == 'E')
	{
		if (check->exit == 0)
			check->exit += 1;
	}
	return (0);
}

int	map_is_valid(char **map)
{
	t_map	check;
	int		i;
	int		j ;

	i = 0;
	j = 0;
	check.len = ft_strlen(map[0]);
	if (check_top(map[0], check.len) < 0)
		return (-1);
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != '1' && map[i][check.len] != '1')
			return (-1);
		j = 0;
		while (map[i][j])
		{
			if (check_middle(map, &check, i, j) < 0)
				return (-1);
			j++;
		}
		++i;
	}
	if (check_down(map[i], check.len) < 0)
		return (-1);
	return (0);
}
