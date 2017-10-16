/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:39:14 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/08 15:45:24 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (!(str = (char*)ft_memalloc(i + 1)))
		return (0);
	str[i] = '\0';
	while (i-- > 0)
		str[i] = f(s[i]);
	return (str);
}
