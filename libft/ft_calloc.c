/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 22:57:53 by hademirc          #+#    #+#             */
/*   Updated: 2024/11/06 13:27:03 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_s;

	total_s = count * size;
	ptr = malloc(total_s);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_s);
	return (ptr);
}
