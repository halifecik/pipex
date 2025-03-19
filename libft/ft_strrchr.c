/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:41:28 by hademirc          #+#    #+#             */
/*   Updated: 2024/10/28 08:02:33 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	tch;

	tch = (unsigned char)c;
	i = ft_strlen(s);
	if (s)
	{
		while (i >= 0)
		{
			if (s[i] == tch)
				return ((char *)&s[i]);
			i--;
		}
	}
	return (0);
}
