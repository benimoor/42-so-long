/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 23:27:19 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/18 19:59:17 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	norm_fix1(t_game *game, int i, int j, int a)
{
	if (game->map[i][j] == 'Q')
		game->map[i][j] = 'E';
	else
		game->map[i][j] = '0';
	if (game->map[i + a][j] == 'E')
	{
		if (game->coin == 0)
			free_and_close(game);
		else
			game->map[i + a][j] = 'Q';
	}
	else
	{
		if (game->map[i + a][j] == 'C')
			game->coin--;
		game->map[i + a][j] = 'P';
	}
}

static void	norm_fix2(t_game *game, int i, int j, int a)
{
	if (game->map[i][j] == 'Q')
		game->map[i][j] = 'E';
	else
		game->map[i][j] = '0';
	if (game->map[i][j + a] == 'E')
	{
		if (game->coin == 0)
			free_and_close(game);
		else
			game->map[i][j + a] = 'Q';
	}
	else
	{
		if (game->map[i][j + a] == 'C')
				game->coin--;
		game->map[i][j + a] = 'P';
	}	
}

void	move_y(t_game *game, int a)
{
	int		i;
	int		j;

	i = 0;
	game->count++;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'Q' || game->map[i][j] == 'P')
				&& game->map[i + a][j] != '1')
			{
				norm_fix1(game, i, j, a);
				return ;
			}
			j++;
		}
		++i;
	}
}

void	move_x(t_game *game, int a)
{
	int		i;
	int		j;

	i = 0;
	game->count++;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] == 'Q' || game->map[i][j] == 'P')
				&& game->map[i][j + a] != '1')
			{
				norm_fix2(game, i, j, a);
				return ;
			}
			j++;
		}
		++i;
	}
}

int	move(int key, t_game *game)
{
	if (!game->count)
		game->count = 1;
	printf("MOVE: %d\n", game->count);
	if (key == KEY_ARROW_RIGHT || key == KEY_D)
		move_x(game, 1);
	else if (key == KEY_ARROW_LEFT || key == KEY_A)
		move_x(game, -1);
	else if (key == KEY_ARROW_UP || key == KEY_W)
		move_y(game, -1);
	else if (key == KEY_ARROW_DOWN || key == KEY_S)
		move_y(game, 1);
	else if (key == KEY_ESC)
		free_and_close(game);
	return (0);
}
