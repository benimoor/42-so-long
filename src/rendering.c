/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:42:18 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/17 23:21:39 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	get_img(t_img *img, void *mlx)
{
	int	size;
	int	size1;

	img->bg = mlx_xpm_file_to_image(mlx, BACKGROUND_PATH,
			&size, &size1);
	img->exit = mlx_xpm_file_to_image(mlx, EXIT_PATH, &size, &size1);
	img->player = mlx_xpm_file_to_image(mlx, PLAYER_PATH, &size, &size1);
	img->coin = mlx_xpm_file_to_image(mlx, COIN_PATH, &size, &size1);
	img->wall = mlx_xpm_file_to_image(mlx, WALL_PATH, &size, &size1);
	img->enemy = mlx_xpm_file_to_image(mlx, ENEMY_PATH, &size, &size1);
}

void	render_img(int *arr, t_game *game)
{
	int		x;
	int		y;
	char	object;

	object = arr[0];
	y = arr[1] * 49;
	x = arr[2] * 49;
	mlx_put_image_to_window(game->mlx, game->win, game->img.bg, x, y);
	if (object == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (object == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.bg, x, y);
	else if (object == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
	else if (object == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
	else if (object == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.coin, x, y);
	else if (object == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, x, y);
	else if (object == 'Q')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, x, y);
	}
}

void	render(t_game *game)
{
	int		i;
	int		j;
	int		arr[3];
	char	*s;
	char	*itoa;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			arr[0] = game->map[i][j];
			arr[1] = i;
			arr[2] = j;
			render_img(arr, game);
			j++;
		}
		i++;
	}
	itoa = ft_itoa(game->count);
	s = ft_strjoin("Move: ", itoa);
	free(itoa);
	mlx_string_put(game->mlx, game->win, 10, 10, rgb(0, 255, 0), s);
	free(s);
}

int	rendering(t_game *game)
{
	render(game);
	mlx_do_sync(game->mlx);
	return (0);
}
