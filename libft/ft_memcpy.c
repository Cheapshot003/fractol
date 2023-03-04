/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:47:52 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 22:15:40 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = dest;
	while (n != 0)
	{	
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest1);
}
