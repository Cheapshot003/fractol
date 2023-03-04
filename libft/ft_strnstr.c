/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <otietz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:44:10 by otietz            #+#    #+#             */
/*   Updated: 2022/10/17 21:35:41 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*charfound(char *big, char *little, size_t len)
{
	char	*b;

	b = big;
	while (*big && *little && *big == *little && len != 0)
	{
		big++;
		little++;
		len--;
	}
	if (*little == '\0')
		return (b);
	return (0);
}

char	*ft_strnstr(char *big, char *little, size_t len)
{
	char	*b;
	char	*l;

	l = little;
	if (len == 0 && *little == '\0')
		return (big);
	if (len == 0)
		return (0);
	if (*little == '\0')
		return (big);
	while (*big && *little && len > 0)
	{
		b = charfound(big, little, len);
		if (b != 0)
			return (b);
		big++;
		little = l;
		len--;
	}
	return (0);
}
