/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <adelhom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:42:56 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/19 13:47:08 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitl(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	if (!s || !c)
		return (NULL);
	index = 0;
	nb_word = ft_splitcount((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_splitcount((const char *)s, c) + 1));
	if (!t)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub((const char *)s, 0, ft_splitl((const char *)s, c));
		if (!t[index])
			return (NULL);
		s = s + ft_splitl(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
