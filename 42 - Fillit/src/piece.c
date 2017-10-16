/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:21:22 by adelhom           #+#    #+#             */
/*   Updated: 2016/12/07 18:04:31 by pmakhzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		free_piece(t_piece *piece)
{
	int y;

	y = 0;
	while (y < piece->dim->y)
	{
		ft_memdel((void **)(&(piece->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(piece->pos)));
	ft_memdel((void **)&piece);
}

t_list		*free_lst_piece(t_list *lst)
{
	t_piece	*piece;
	t_list	*tmp;

	while (lst)
	{
		piece = (t_piece *)lst->content;
		tmp = lst->next;
		free_piece(piece);
		ft_memdel((void **)&lst);
		lst = tmp;
	}
	return (NULL);
}

t_piece		*build_piece(char **pos, t_point *dim, char value)
{
	t_piece		*piece;

	piece = ft_memalloc(sizeof(t_piece));
	piece->pos = pos;
	piece->dim = ft_memalloc(sizeof(t_point));
	piece->dim = dim;
	piece->value = value;
	return (piece);
}

t_bool		can_place_piece(t_piece *piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piece->dim->x)
	{
		j = 0;
		while (j < piece->dim->y)
		{
			if (piece->pos[j][i] == FILL_CHAR &&
			map->output[y + j][x + i] != EMPTY_CHAR)
				return (FALSE);
			j++;
		}
		i++;
	}
	place_piece(piece, map, ft_pointnew(x, y), piece->value);
	return (TRUE);
}

void		place_piece(t_piece *piece, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < piece->dim->x)
	{
		j = 0;
		while (j < piece->dim->y)
		{
			if (piece->pos[j][i] == FILL_CHAR)
				map->output[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}
