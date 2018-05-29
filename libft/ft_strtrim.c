/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:28:04 by agifford          #+#    #+#             */
/*   Updated: 2018/05/08 00:04:09 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*tmp;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		tmp = (char *)s + i;
		if (*tmp == '\0')
			return (ft_strdup(tmp));
		i = ft_strlen(tmp);
		i--;
		while (tmp[i] == ' ' || tmp[i] == '\t' || tmp[i] == '\n')
			i--;
		return (ft_strndup(tmp, i + 1));
	}
	return (NULL);
}
