/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:35:10 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 22:15:22 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (d > s)
	{
		while (n--)
		{
			*(d + n) = *(s + n);
		}
		return (dest);
	}
	else
	{
		dest = ft_memcpy(dest, src, n);
	}
	return (dest);
}
