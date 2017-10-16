/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:16:31 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/15 23:10:40 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_trim(char *s)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s))))
		return (0);
	ft_strcpy(str, s);
	ft_strdel(&s);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	char	*tail;
	size_t	i;

	if (!s)
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(s) + 1)))
		return (0);
	tail = (char *)s + (ft_strlen(s) - 1);
	i = 0;
	while (IS_WHITESPACE(*s))
		s++;
	while (IS_WHITESPACE(*tail))
		tail--;
	while (s <= tail)
	{
		tmp[i] = *s;
		i++;
		s++;
	}
	tmp[i] = '\0';
	return (build_trim(tmp));
}
