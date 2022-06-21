/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:06:54 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/18 20:00:24 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	norm_fix_for_gm(int *a, int fd, char **tmp, char **map)
{
	while (get_next_line(fd, tmp) > 0)
	{
		if (*tmp != 0)
			*map = ft_gnl_strjoin(*map, *tmp);
		if ((int)(ft_strlen(*tmp)) != a[1])
		{
			write(2, "ya qu ara\n", 10);
			free(*tmp);
			free(*map);
			exit(0);
		}
		free(*tmp);
	}
}

int	check_name(char *path)
{
	char	*format;
	int		i;

	i = 0;
	format = ".ber";
	while (path[i + 4])
		i++;
	while (path[i] && path[i] == *format++)
		i++;
	if (i != (int)(ft_strlen(path)))
		return (-1);
	return (0);
}

char	**get_map(char *path)
{
	char	*map;
	char	*tmp;
	char	**res;
	int		fd;
	int		a[2];

	map = 0;
	fd = open(path, O_RDONLY);
	if (check_name(path) < 0)
		return (NULL);
	if (get_next_line(fd, &tmp) > 0)
	{
		map = ft_gnl_strjoin(map, tmp);
		free(tmp);
	}
	else
		return (NULL);
	a[1] = ft_strlen(tmp);
	norm_fix_for_gm(a, fd, &tmp, &map);
	res = ft_split(map, '\n');
	free(map);
	if (map_is_valid(res) == 0)
		return (res);
	return (NULL);
}

int	get_coin(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				++count;
			++j;
		}
		++i;
	}
	return (count);
}
