/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:21:45 by adelhom           #+#    #+#             */
/*   Updated: 2016/12/07 18:04:33 by pmakhzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		get_fd(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		close(fd);
	return (fd);
}

int				main(int argc, char **argv)
{
	int	fd;
	t_list	*lst;
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl_fd(USAGE, 2);
		return (0);
	}
	if ((fd = get_fd(argv[1])) < 0)
	{
		ft_putendl_fd(USAGE, 2);
		return (0);
	}
	if (!(lst = read_input(fd)))
	{
		ft_putendl(ERROR);
		return (0);
	}
	map = solve_map(lst);
	print_map(map);
	free_map(map);
	free_lst_piece(lst);
	return (0);
}
