/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 20:11:52 by agifford          #+#    #+#             */
/*   Updated: 2018/05/08 00:28:58 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char sym;
	unsigned char *src;

	sym = c;
	src = (unsigned char *)s;
	while (n--)
	{
		if (*src == sym)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
