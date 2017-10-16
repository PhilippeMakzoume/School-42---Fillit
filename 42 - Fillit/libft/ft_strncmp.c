/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:47:18 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/06 16:23:30 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (n - 1 && *s1 == *s2 && *s1)
		{
			s1++;
			s2++;
			n--;
		}
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	}
	return (0);
}
