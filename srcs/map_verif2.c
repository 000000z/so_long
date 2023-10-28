/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:19:32 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/02 14:21:50 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_letter(t_jeu *jeu)
{
	if (jeu->perso != 1)
		return (ft_printf("Error\nil faut 1 personnage !\n"), 0);
	if (jeu->exit != 1)
	{
		ft_printf("Error\nil faut 1 sortie !\n");
		return (0);
	}
	if (jeu->collectible < 1)
	{
		ft_printf("Error\nil faut au moins un collectible !\n");
		return (0);
	}
	if (jeu->nbr_ligne >= jeu->len)
	{
		ft_printf("Error\nla map doit etre rectangle !\n");
		return (0);
	}
	if (jeu->len > 31)
	{
		ft_printf("Error\nmap trop longue !\n");
		return (0);
	}
	return (1);
}

int	check_valid_name(char *av1)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av1) - 1;
	if (av1[len] == 'r')
		i++;
	if (av1[len - 1] == 'e')
		i++;
	if (av1[len - 2] == 'b')
		i++;
	if (av1[len - 3] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (ft_printf("Error\nmauvais nom de map"), 0);
}

int	line_size(t_jeu *jeu)
{
	int	i;
	int	len2;

	i = 0;
	jeu->len = ft_strlen(jeu->map_parser[i]);
	while (jeu->map_parser[i])
	{
		len2 = ft_strlen(jeu->map_parser[i]);
		if (jeu->len != len2)
		{
			ft_printf("Error\nLes lignes ne font pas la meme taille ! \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_empty(t_jeu *jeu)
{
	int	i;
	int	len;
	int	len2;

	i = 2;
	len = ft_strlen(jeu->map[1]);
	if (jeu->nbr_ligne > 16)
		return (ft_printf("Error\ntrop de lignes"), 0);
	if (len != 0)
		return (1);
	while (jeu->map[i])
	{
		len2 = ft_strlen(jeu->map[i]);
		if (len2 != len)
		{
			return (1);
		}
		i++;
	}
	ft_printf ("Error\n map vide");
	libere_carte (jeu->map);
	return (0);
}

int	check_map(t_jeu *jeu)
{
	if (!(line_size(jeu)))
	{
		libere_carte(jeu->map);
		libere_carte(jeu->map_parser);
		return (0);
	}
	if (!(mur_haut_bas(jeu)))
	{
		libere_carte(jeu->map);
		libere_carte(jeu->map_parser);
		return (0);
	}
	if (!(contenu_ligne(1, jeu)))
	{
		libere_carte(jeu->map);
		libere_carte(jeu->map_parser);
		return (0);
	}
	if (!(check_letter(jeu)))
	{
		libere_carte(jeu->map);
		libere_carte(jeu->map_parser);
		return (0);
	}
	return (1);
}
