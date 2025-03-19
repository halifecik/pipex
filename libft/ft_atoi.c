/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:31:07 by hademirc          #+#    #+#             */
/*   Updated: 2024/11/06 12:18:23 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	a = 0;
	while ((str[a] == 32) || (str[a] >= 9 && str[a] <= 13))
	{
		a++;
	}
	if ((str[a] == 45) || (str[a] == 43))
	{
		if (str[a] == 45)
			sign = -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		result = result * 10 + (str[a] - 48);
		a++;
	}
	return (result * sign);
}
