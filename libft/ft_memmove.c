/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:41:09 by hademirc          #+#    #+#             */
/*   Updated: 2024/10/20 23:15:50 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*rtn;

	if (!dst && !src)
		return (0);
	rtn = dst;
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *)dst + len - 1) = *((char *)src + len - 1);
			len--;
		}
	}
	else
	{
		while (len)
		{
			*((char *)dst++) = *((char *)src++);
			len--;
		}
	}
	return (rtn);
}
