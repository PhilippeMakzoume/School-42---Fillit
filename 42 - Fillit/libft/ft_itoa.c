/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:51:33 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/08 15:05:56 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		tmp;
	size_t	len;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	tmp = n;
	while ((tmp = tmp / 10))
		len++;
	if ((str = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	str[len--] = '\0';
	str[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		str[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		str[len] = '-';
	return (str);
}
