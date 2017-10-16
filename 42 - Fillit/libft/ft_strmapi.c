/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:45:41 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/10 18:02:16 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[i] = f(i, s[i]);
	return (str);
}
