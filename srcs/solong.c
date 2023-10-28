/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:59:26 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/03 16:58:41 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_game(int i, int j, t_jeu *jeu)
{
	jeu->map_parser[jeu->xe][jeu->ye] = '0';
	while (jeu->map_parser[i])
	{
		j = 0;
		while (jeu->map_parser[i][j])
		{
			if (jeu->map_parser[i][j] == '1')
				mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->wall, j
					* 64, i * 64);
			if (jeu->map_parser[i][j] == '0')
				mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->ground, j
					* 64, i * 64);
			if (jeu->map_parser[i][j] == 'P')
				mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->personnage,
					j * 64, i * 64);
			if (jeu->map_parser[i][j] == 'C')
				mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->fish, j
					* 64, i * 64);
			j++;
		}
		i++;
	}
}

int	create_all_images(int i, int j, t_jeu	*jeu)
{
	jeu->wall = mlx_xpm_file_to_image(jeu->mlx, "xmlpic/seaweed.xpm", &i, &j);
	if (!jeu->wall)
		return (0);
	jeu->ground = mlx_xpm_file_to_image(jeu->mlx, "xmlpic/water.xpm", &i, &j);
	if (!jeu->ground)
		return (0);
	jeu->personnage = mlx_xpm_file_to_image(jeu->mlx, "xmlpic/boat.xpm",
			&i, &j);
	if (!jeu->personnage)
		return (0);
	jeu->sortit = mlx_xpm_file_to_image(jeu->mlx, "xmlpic/exit.xpm", &i, &j);
	if (!jeu->sortit)
		return (0);
	jeu->fish = mlx_xpm_file_to_image(jeu->mlx, "xmlpic/fish.xpm", &i, &j);
	if (!jeu->fish)
		return (0);
	return (1);
}

int	destroy_everything(t_jeu *jeu)
{
	if (jeu->wall)
		mlx_destroy_image(jeu->mlx, jeu->wall);
	if (jeu->ground)
		mlx_destroy_image(jeu->mlx, jeu->ground);
	if (jeu->sortit)
		mlx_destroy_image(jeu->mlx, jeu->sortit);
	if (jeu->personnage)
		mlx_destroy_image(jeu->mlx, jeu->personnage);
	if (jeu->fish)
		mlx_destroy_image(jeu->mlx, jeu->fish);
	if (jeu->mlx_win)
		mlx_destroy_window(jeu->mlx, jeu->mlx_win);
	if (jeu->mlx)
	{
		mlx_destroy_display(jeu->mlx);
		free(jeu->mlx);
	}
	libere_tout(jeu);
	exit (0);
}

void	destroy_win_disp(t_jeu *jeu)
{
	if (jeu->mlx_win)
		mlx_destroy_window(jeu->mlx, jeu->mlx_win);
	if (jeu->mlx)
		mlx_destroy_display(jeu->mlx);
}
