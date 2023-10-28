/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:46:44 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/02 14:21:21 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int				width;
	int				height;
	static t_jeu	jeu = {0};

	width = 64;
	height = 64;
	if (argc == 2)
	{
		if (!(check_valid_name(argv[1])))
			return (0);
		if (!(creation_carte(argv[1], &jeu)))
			return (0);
		if (!(check_empty(&jeu)))
			return (0);
		jeu.map_parser = copy_map(jeu.map);
		if (!(check_map(&jeu)))
			return (0);
		jeu.map_flood = copy_map(jeu.map);
		flood_fill(jeu.x, jeu.y, &jeu);
		if (!(check_flood(&jeu)))
			return (0);
		mlxmain(width, height, &jeu);
	}
	return (0);
}
