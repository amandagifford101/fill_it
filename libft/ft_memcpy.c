/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:02:57 by agifford          #+#    #+#             */
/*   Updated: 2018/05/02 23:58:54 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (n == 0 || dst == src)
		return ((void*)dst);
	s = (char*)src;
	d = (char*)dst;
	while (n--)
		*d++ = *s++;
	return ((void*)dst);
}
