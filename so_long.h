/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:04:50 by adzinabi          #+#    #+#             */
/*   Updated: 2023/10/03 17:03:14 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "./GNL/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx_int.h"
# include "./mlx/mlx.h"

typedef struct s_jeu
{
	char	**map;
	int		nbr_ligne;
	int		collectible;
	int		perso;
	int		exit;
	int		len;
	char	**map_flood;
	char	**map_parser;
	int		x;
	int		y;
	int		xe;
	int		ye;
	int		count;
	void	*wall;
	void	*ground;
	void	*personnage;
	void	*sortit;
	void	*fish;
	void	*mlx;
	void	*mlx_win;
}			t_jeu;

int		creation_carte(char *av1, t_jeu *jeu);
void	nombredeligne(char *av1, t_jeu *jeu);
int		mur_haut_bas(t_jeu *jeu);
int		contenu_ligne(int i, t_jeu *jeu);
int		boucle_contenu_ligne(int i, int j, int longueur, t_jeu	*jeu);
int		check_letter(t_jeu *jeu);
int		check_empty(t_jeu *jeu);
int		error_letter(t_jeu *jeu);
int		check_valid_name(char *av1);
void	libere_carte(char **carte);
int		check_map(t_jeu *jeu);
void	libere_tout(t_jeu *jeu);
void	position_exit(int i, int j, t_jeu	*jeu);

int		destroy_everything(t_jeu *jeu);
void	destroy_win_disp(t_jeu *jeu);
int		create_all_images(int i, int j, t_jeu	*jeu);
void	open_game(int i, int j, t_jeu *jeu);
int		on_keypress(int keysym, t_jeu *jeu);
int		on_destroy(t_jeu	*jeu);
int		touchekey(int keysym, t_jeu *jeu);
int		mlxmain(int width, int height, t_jeu *jeu);
void	c_chao(t_jeu *jeu);

void	va_enbas(t_jeu	*jeu);
void	va_enhaut(t_jeu	*jeu);
void	va_agauche(t_jeu	*jeu);
void	va_adroite(t_jeu	*jeu);

int		flood_fill(int x, int y, t_jeu *jeu);
char	**copy_map(char **map);
char	*copy(const char *src);
int		check_flood(t_jeu *jeu);
int		boucle_check_flood(int i, int j, int longueur, t_jeu *jeu);

#endif