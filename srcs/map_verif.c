/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:28:10 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/02 14:20:43 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	nombredeligne(char *av1, t_jeu *jeu)
{
	int		fd;
	char	*line;

	jeu->nbr_ligne = 0;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL)
			break ;
		free(line);
		line = get_next_line(fd);
		jeu->nbr_ligne++;
	}
	free(line);
	close(fd);
}

void	libere_carte(char **carte)
{
	int	i;

	if (!carte)
		return ;
	i = 0;
	while (carte[i])
	{
		free(carte[i]);
		i++;
	}
	free(carte);
}

int	creation_carte(char *av1, t_jeu *jeu)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	nombredeligne(av1, jeu);
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nLe fichier n'existe pas\n"), 0);
	if (jeu->nbr_ligne <= 1)
		return (ft_printf("Error\npas asser de ligne"), 0);
	jeu->map = malloc(sizeof(char *) * (jeu->nbr_ligne + 1));
	if (!jeu->map)
		return (free(jeu->map), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		jeu->map[i] = copy(line);
		free(line);
		i++;
	}
	jeu->map[i] = NULL;
	return (close(fd), 1);
}

int	mur_haut_bas(t_jeu *jeu)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (jeu->map_parser[0][i])
	{
		if (jeu->map_parser[0][i] != '1' && jeu->map_parser[0][i] != '\n')
		{
			ft_printf("Error\nLe mur du haut ne doit contenir que des 1!");
			return (0);
		}
		i++;
	}
	while (jeu->map_parser[jeu->nbr_ligne - 1][j])
	{
		if (jeu->map_parser[jeu->nbr_ligne - 1][j] != '1'
			&& jeu->map_parser[jeu->nbr_ligne - 1][j] != '\n')
		{
			ft_printf("Error\nLe mur du bas ne doit contenir que des 1!");
			return (0);
		}
		j++;
	}
	return (1);
}

int	contenu_ligne(int i, t_jeu *jeu)
{
	int	j;
	int	longueur;

	i = 1;
	j = 0;
	longueur = ft_strlen(jeu->map_parser[i]);
	if (!(boucle_contenu_ligne(i, j, longueur, jeu)))
		return (0);
	return (1);
}
