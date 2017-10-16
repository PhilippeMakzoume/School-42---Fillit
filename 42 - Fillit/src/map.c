/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:21:39 by adelhom           #+#    #+#             */
/*   Updated: 2016/12/07 18:04:32 by pmakhzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->output[i]));
		i++;
	}
	ft_memdel((void **)&(map->output));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->output[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*build_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->output = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->output[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->output[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

t_bool		backtrack_map(t_map *map, t_list *lst)
{
	int			x;
	int			y;
	t_piece		*piece;

	if (lst == NULL)
		return (TRUE);
	y = 0;
	piece = (t_piece *)(lst->content);
	while (y < map->size - piece->dim->y + 1)
	{
		x = 0;
		while (x < map->size - piece->dim->x + 1)
		{
			if (can_place_piece(piece, map, x, y))
			{
				if (backtrack_map(map, lst->next))
					return (TRUE);
				else
					place_piece(piece, map, ft_pointnew(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_map	*solve_map(t_list *lst)
{
	t_map	*map;
	int		size;

	size = ft_sqrtint(ft_lstsize(lst) * 4);
	map = build_map(size);
	while (!backtrack_map(map, lst))
	{
		size++;
		free_map(map);
		map = build_map(size);
	}
	return (map);
}
