/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <otietz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:55:11 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 22:22:44 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	char				*a;
	long unsigned int	i;

	i = 0;
	a = malloc(nitems * size);
	if (0 == a)
		return (0);
	while (i <= nitems * size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
