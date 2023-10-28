/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:11:31 by adzinabi          #+#    #+#             */
/*   Updated: 2023/09/27 15:41:18 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**copy_map(char **map)
{
	char	**dst;
	int		i;

	i = 0;
	while (map[i])
		i++;
	dst = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dst[i] = copy(map[i]);
		if (dst[i] == NULL)
		{
			while (i >= 0)
				free(dst[i--]);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

int	flood_fill(int x, int y, t_jeu *jeu)
{	
	if (jeu->map_flood[x][y] == '1' || jeu->map_flood[x][y] == 'V')
		return (0);
	jeu->map_flood[x][y] = 'V';
	if (flood_fill(x - 1, y, jeu) || flood_fill(x + 1, y, jeu)
		|| flood_fill(x, y - 1, jeu) || flood_fill(x, y + 1, jeu))
		return (1);
	return (0);
}

int	check_flood(t_jeu *jeu)
{
	int	i;
	int	j;
	int	longueur;

	j = 0;
	i = 0;
	longueur = ft_strlen(jeu->map_flood[i]);
	if (!(boucle_check_flood(i, j, longueur, jeu)))
		return (0);
	return (1);
}

void	libere_tout(t_jeu *jeu)
{
	if (jeu->map)
		libere_carte(jeu->map);
	if (jeu->map_parser)
		libere_carte(jeu->map_parser);
	if (jeu->map_flood)
		libere_carte(jeu->map_flood);
}
