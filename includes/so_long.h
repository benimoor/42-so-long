/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:31:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/06/18 20:02:23 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#if defined(__APPLE__) && defined(__MACH__)
    #define MAX_OPEN_FILES OPEN_MAX
	# include "mlx.h"
#elif defined(__linux__)
    #define MAX_OPEN_FILES FOPEN_MAX
	# include "../minilibx-linux/mlx.h"
#else
    #error "Unsupported OS"
#endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "keys.h"

# define COIN_PATH "./src/img/final/coin.xpm"
# define PLAYER_PATH "./src/img/final/player.xpm"
# define WALL_PATH  "./src/img/final/wall.xpm"
# define BACKGROUND_PATH "./src/img/final/background.xpm"
# define EXIT_PATH "./src/img/final/exit.xpm"
# define ENEMY_PATH "./src/img/final/enemy.xpm"

typedef struct s_img
{
	void	*coin;
	void	*player;
	void	*wall;
	void	*bg;
	void	*enemy;
	void	*exit;
}			t_img;

typedef struct s_game
{
	int		coin;
	int		count;
	void	*mlx;
	void	*player;
	void	*win;
	char	**map;
	t_img	img;
}			t_game;

typedef struct s_map
{
	int		len;
	int		coin;
	int		wall;
	int		player;
	int		enemy;
	int		exit;
}			t_map;

void	get_img(t_img *img, void *mlx);
void	render_img(int *arr, t_game *game);
void	render(t_game *game);
void	move_y(t_game *game, int a);
void	move_y(t_game *game, int a);
int		rendering(t_game *game);
int		get_coin(char **map);
int		move(int key, t_game *game);
int		free_and_close(t_game *game);
int		map_is_valid(char **map);
char	**get_map(char *path);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);

#endif
