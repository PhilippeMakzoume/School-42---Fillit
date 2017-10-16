/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:21:15 by adelhom           #+#    #+#             */
/*   Updated: 2016/12/07 18:04:34 by pmakhzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**extract_input(char *buffer, t_point *min, t_point *max)
{
	char	**extract;
	int		i;
	int		start;
	int		end;

	extract = (char **)ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		start = (min->x) + (i + min->y) * 5;
		end = max->x - min->x + 1;
		extract[i] = ft_strsub(buffer, start, end);
		i++;
	}
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (extract);
}

t_piece	*build_input(char *buffer, char value)
{
	int			i;
	t_point		*min;
	t_point		*max;
	t_point		*dim;
	t_piece		*piece;

	i = 0;
	min = ft_pointnew(3, 3);
	max = ft_pointnew(0, 0);
	while (buffer[i])
	{
		if (buffer[i] == FILL_CHAR)
		{
			min->y = (i / 5 < min->y) ? i / 5 : min->y;
			max->y = (i / 5 > max->y) ? i / 5 : max->y;
			min->x = (i % 5 < min->x) ? i % 5 : min->x;
			max->x = (i % 5 > max->x) ? i % 5 : max->x;
		}
		i++;
	}
	dim = ft_pointnew(max->x - min->x + 1, max->y - min->y + 1);
	piece = build_piece(extract_input(buffer, min, max), dim, value);
	return (piece);
}

t_bool	valide_diese(char *buffer)
{
	int		i;
	int		link;
	int		diese;

	i = 0;
	link = 0;
	diese = 0;
	while (buffer[i])
	{
		if (buffer[i] == FILL_CHAR)
		{
			link += (buffer[i - 1] == FILL_CHAR) ? 1 : 0;
			link += (buffer[i - 5] == FILL_CHAR) ? 1 : 0;
			link += (buffer[i + 1] == FILL_CHAR) ? 1 : 0;
			link += (buffer[i + 5] == FILL_CHAR) ? 1 : 0;
			diese++;
		}
		i++;
	}
	if (diese != 4 || link <= 4)
		return (FALSE);
	return (TRUE);
}

t_bool	good_input(char *buffer, int last)
{
	int	i;
	int	backline;
	int	empty;
	int	fill;

	i = 0;
	backline = 0;
	empty = 0;
	fill = 0;
	if (!valide_diese(buffer))
		return (FALSE);
	while (buffer[i])
	{
		if ((!((i + 1) % 5) || i == 21) && buffer[i] == '\n')
			backline++;
		else if (buffer[i] == EMPTY_CHAR)
			empty++;
		i++;
	}
	if ((backline == 4 && i == 20 && last != 1) || empty != 12)
		return (FALSE);
	else if ((backline == 5 && i != 21) || empty != 12)
		return (FALSE);
	return (TRUE);
}

t_list	*read_input(int fd)
{
	char	*buffer;
	char	letter;
	t_point	*dat;
	t_list	*lst;
	t_piece	*p;

	buffer = ft_strnew(21);
	dat = ft_pointnew(0, 0);
	letter = 'A';
	lst = NULL;
	while ((dat->x = read(fd, buffer, 21)) >= 20 && dat->y == 0)
	{
		dat->y += (dat->x == 20) ? 1 : 0;
		if (!good_input(buffer, dat->y) || !(p = build_input(buffer, letter++)))
		{
			ft_memdel((void **)&buffer);
			return (free_lst_piece(lst));
		}
		ft_lstpushback(&lst, ft_lstnew(p, sizeof(t_piece)));
		ft_memdel((void **)&p);
	}
	ft_memdel((void **)&buffer);
	if (dat->x != 0 || dat->y != 1)
		return (free_lst_piece(lst));
	return (lst);
}
