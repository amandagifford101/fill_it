/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:21:12 by agifford          #+#    #+#             */
/*   Updated: 2018/05/07 23:42:15 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		sym;
	unsigned const char	*s;
	unsigned char		*d;

	sym = (unsigned char)c;
	s = (unsigned const char*)src;
	d = (unsigned char*)dst;
	while (n--)
	{
		if (*s == sym)
		{
			*d = *s;
			return (d + 1);
		}
		else
			*d++ = *s++;
	}
	return (NULL);
}
