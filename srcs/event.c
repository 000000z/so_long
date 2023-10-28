/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:07:50 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/03 17:01:44 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_keypress(int keysym, t_jeu *jeu)
{
	(void)jeu;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

int	touchekey(int keysym, t_jeu *jeu)
{
	int		count;

	count = 0;
	if (keysym == 65307)
	{
		destroy_everything(jeu);
		exit(EXIT_SUCCESS);
	}
	if (keysym == 100 || keysym == 65363)
		va_adroite(jeu);
	if (keysym == 97 || keysym == 65361)
		va_agauche(jeu);
	if (keysym == 119 || keysym == 65362)
		va_enhaut(jeu);
	if (keysym == 115 || keysym == 65364)
		va_enbas(jeu);
	if (jeu->map_parser[jeu->x][jeu->y] == 'C')
	{
		jeu->collectible--;
		jeu->map_parser[jeu->x][jeu->y] = '0';
	}
	c_chao(jeu);
	return (0);
}

void	c_chao(t_jeu *jeu)
{
	if (jeu->collectible == 0)
	{
		jeu->map_parser[jeu->xe][jeu->ye] = 'E';
		mlx_put_image_to_window(jeu->mlx, jeu->mlx_win, jeu->sortit, jeu->ye
			* 64, jeu->xe * 64);
	}
}

void	position_exit(int i, int j, t_jeu	*jeu)
{
	jeu->xe = i;
	jeu->ye = j;
}
