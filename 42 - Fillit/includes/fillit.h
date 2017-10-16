/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:21:51 by adelhom           #+#    #+#             */
/*   Updated: 2016/12/06 15:43:09 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define USAGE "usage: fillit input_file"
# define ERROR "error"
# define FILL_CHAR '#'
# define EMPTY_CHAR '.'

# include "../libft/libft.h"

typedef struct	s_map
{
	char		**output;
	int			size;
}				t_map;

typedef struct	s_piece
{
	char		**pos;
	t_point		*dim;
	char		value;
}				t_piece;

char			**extract_input(char *buffer, t_point *min, t_point *max);
t_piece			*build_input(char *buffer, char value);
t_bool			valide_input(char *buffer);
t_list			*read_input(int fd);

void			free_map(t_map *map);
void			print_map(t_map *map);
t_map			*build_map(int size);
t_bool			backtrack_map(t_map *map, t_list *lst);
t_map			*solve_map(t_list *lst);

t_list			*free_lst_piece(t_list *lst);
void			free_piece(t_piece *piece);
t_piece			*build_piece(char **pos, t_point *dim, char c);
t_bool			can_place_piece(t_piece *piece, t_map *map, int x, int y);
void			place_piece(t_piece *piece, t_map *map, t_point *point, char c);

#endif
