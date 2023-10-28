/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boucle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:06:45 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/03 16:39:27 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	boucle_contenu_ligne(int i, int j, int longueur, t_jeu	*jeu)
{
	while (i < jeu->nbr_ligne - 1)
	{
		while (jeu->map_parser[i][j] && j < longueur - 1)
		{
			if (jeu->map_parser[i][0] != '1'
				|| jeu->map_parser[i][longueur - 1] != '1')
				return (ft_printf("Error\nLa map doit etre entourer de 1!\n"), 0);
			else if (jeu->map_parser[i][j] != '0'
			&& jeu->map_parser[i][j] != '1'
			&& jeu->map_parser[i][j] != 'C'
			&& jeu->map_parser[i][j] != 'P' && jeu->map_parser[i][j] != 'E')
				return (ft_printf("Error\nCaractère incompatible\n"), 0);
			if (jeu->map_parser[i][j] == 'P')
			{
				jeu->x = i;
				jeu->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_letter(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	while (jeu->map_parser[i])
	{
		j = 0;
		while (jeu->map_parser[i][j])
		{
			if (jeu->map_parser[i][j] == 'C')
				jeu->collectible = jeu->collectible + 1;
			else if (jeu->map_parser[i][j] == 'P')
				jeu->perso = jeu->perso + 1;
			else if (jeu->map_parser[i][j] == 'E')
			{
				jeu->exit = jeu->exit + 1;
				position_exit(i, j, jeu);
			}
			j++;
		}
		i++;
	}
	if (!(error_letter(jeu)))
		return (0);
	return (1);
}

int	boucle_check_flood(int i, int j, int longueur, t_jeu *jeu)
{
	while (jeu->map_flood[i] && i < jeu->nbr_ligne)
	{
		j = 0;
		while (jeu->map_flood[i][j] && j < longueur - 1)
		{
			if (jeu->map_flood[i][0] != '1'
				|| jeu->map_flood[i][longueur - 1] != '1')
			{
				libere_tout(jeu);
				return (ft_printf("Error\nendroit inaccesible\n"), 0);
			}
			else if (jeu->map_flood[i][j] != 'V' && jeu->map_flood[i][j] != '1')
			{
				libere_tout(jeu);
				return (ft_printf("Error\nendroit inaccesible\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
