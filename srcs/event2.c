/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:29:26 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/03 16:57:34 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	va_adroite(t_jeu	*jeu)
{
	if (jeu->collectible <= 0 && jeu->map_parser[jeu->x][jeu->y + 1] == 'E')
	{
		destroy_everything(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_parser[jeu->x][jeu->y + 1] == '1')
		return ;
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->personnage,
		(jeu->y + 1) * 64, jeu->x * 64);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->ground,
		(jeu->y) * 64, jeu->x * 64);
	jeu->y = jeu->y + 1;
	jeu->count++;
	ft_printf("nombre de mouvement: %d\n", jeu->count);
}

void	va_agauche(t_jeu	*jeu)
{
	if (jeu->collectible <= 0 && jeu->map_parser[jeu->x][jeu->y - 1] == 'E')
	{
		destroy_everything(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_parser[jeu->x][jeu->y - 1] == '1')
		return ;
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->personnage, (jeu->y - 1) * 64, jeu->x * 64);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->ground, (jeu->y) * 64, jeu->x * 64);
	jeu->y = jeu->y - 1;
	jeu->count++;
	ft_printf("nombre de mouvement: %d\n", jeu->count);
}

void	va_enhaut(t_jeu	*jeu)
{
	if (jeu->collectible <= 0 && jeu->map_parser[jeu->x - 1][jeu->y] == 'E')
	{
		destroy_everything(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_parser[jeu->x - 1][jeu->y] == '1')
		return ;
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->personnage, jeu->y * 64, (jeu->x - 1) * 64);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->ground, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x - 1;
	jeu->count++;
	ft_printf("nombre de mouvement: %d\n", jeu->count);
}

void	va_enbas(t_jeu	*jeu)
{
	if (jeu->collectible <= 0 && jeu->map_parser[jeu->x + 1][jeu->y] == 'E')
	{
		printf("test");
		destroy_everything(jeu);
		exit(EXIT_SUCCESS);
	}
	if (jeu->map_parser[jeu->x + 1][jeu->y] == '1')
		return ;
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->personnage, jeu->y * 64, (jeu->x + 1) * 64);
	mlx_put_image_to_window(jeu->mlx, jeu->mlx_win,
		jeu->ground, jeu->y * 64, jeu->x * 64);
	jeu->x = jeu->x + 1;
	jeu->count++;
	ft_printf("nombre de mouvement: %d\n", jeu->count);
}

int	mlxmain(int width, int height, t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	jeu->mlx = mlx_init();
	if (!jeu->mlx)
		return (libere_tout(jeu), 0);
	jeu->mlx_win = mlx_new_window(jeu->mlx, jeu->len * 64,
			jeu->nbr_ligne * 64, "Hello world!");
	if (!jeu->mlx_win)
		return (libere_tout(jeu), 0);
	if (!(create_all_images(width, height, jeu)))
		return (libere_tout(jeu), destroy_win_disp(jeu), 1);
	open_game(i, j, jeu);
	mlx_hook(jeu->mlx_win, DestroyNotify, StructureNotifyMask,
		&destroy_everything, jeu);
	mlx_hook(jeu->mlx_win, KeyRelease, KeyReleaseMask, &on_keypress, jeu);
	mlx_key_hook(jeu->mlx_win, &touchekey, jeu);
	mlx_loop(jeu->mlx);
	destroy_everything(jeu);
	libere_tout(jeu);
	return (1);
}
