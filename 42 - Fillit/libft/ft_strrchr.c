/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:54 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/15 22:50:07 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	tmp += ft_strlen(s);
	while (*tmp != (char)c && tmp != (char*)s)
		tmp--;
	if (*tmp == (char)c)
		return ((char *)tmp);
	return (NULL);
}
