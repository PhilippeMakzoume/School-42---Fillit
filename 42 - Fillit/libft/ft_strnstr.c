/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:01:47 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/10 18:01:53 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	size = ft_strlen(little);
	if (!*little)
		return ((char*)big);
	while (*big && size <= len--)
	{
		if (!ft_memcmp(big++, little, size))
			return ((char*)big - 1);
	}
	return (NULL);
}
