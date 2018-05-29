/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:20:35 by agifford          #+#    #+#             */
/*   Updated: 2018/05/08 15:08:00 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	long long int	negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while (ISNONPRINT(x))
		i++;
	if ((str[i] == '-' && (negative = -1)) || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (negative * nbr);
		else
			nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (negative * nbr);
}
