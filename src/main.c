/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:13:46 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/18 20:37:52 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	int	width;
	int	height;

	width = (int)(ft_strlen(game->map[0]));
	height = 0;
	while (game->map[height])
		height++;
	game->mlx = mlx_init();
	get_img(&game->img, game->mlx);
	game->win = mlx_new_window(game->mlx, (width * 50), (height * 50),
			"PxikDzknik");
	mlx_key_hook(game->win, move, game);
	mlx_hook(game->win, 17, 1L << 0, free_and_close, game);
	mlx_loop_hook(game->mlx, rendering, game);
	mlx_loop(game->mlx);
}

int	free_and_close(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac == 2)
	{
		game.map = get_map(av[1]);
		if (!game.map)
		{
			write(2, "ya qu ara\n", ft_strlen("ya qu ara\n"));
			exit(1);
		}
		game.coin = get_coin(game.map);
		start_game(&game);
	}
	else
		write(2, "argumentnerid het mi ban nitoya qurs\n",
			ft_strlen("argumentnerid het mi ban nitoya qurs\n"));
	return (0);
}
