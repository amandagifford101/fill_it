/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:30:42 by agifford          #+#    #+#             */
/*   Updated: 2018/05/08 00:02:41 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (s2[k] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s1[i + k] == s2[k] && s2[k] && s1[i + k])
		{
			if (s2[k + 1] == '\0')
				return ((char *)s1 + i);
			k++;
		}
		k = 0;
		i++;
	}
	return (NULL);
}
