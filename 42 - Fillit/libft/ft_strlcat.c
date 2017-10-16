/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelhom <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:28:41 by adelhom           #+#    #+#             */
/*   Updated: 2016/11/05 14:59:21 by adelhom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int size_d;
	unsigned int size_s;

	i = 0;
	while (dest[i] != '\0')
		i++;
	size_d = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	size_s = i;
	i = 0;
	while (src[i] != '\0' && (size_d + i) < (size - 1))
	{
		dest[size_d + i] = src[i];
		i++;
	}
	dest[size_d + i] = '\0';
	return (size_s + ((size_d < size) ? size_d : size));
}
