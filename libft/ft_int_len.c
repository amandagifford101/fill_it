/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:04:41 by agifford          #+#    #+#             */
/*   Updated: 2018/05/08 00:19:14 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_len(int n)
{
	int i;
	int negative;
	int len;
	int	neg_len;
	int len_one;

	i = 0;
	len = 0;
	negative = 0;
	if (n == '-')
		negative = 1;
	while (((n > 10) || (n < -10)) && i++)
		n = (n / 10);
	len_one = 1;
	len = i + 1;
	neg_len = i + 2;
	if (n == 0)
		return (len_one);
	else if (negative == 1)
		return (neg_len);
	else
		return (len);
}
