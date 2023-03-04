/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:40:36 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 22:18:49 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	reverse(char *s)
{
	size_t	len;
	size_t	i;
	char	temp;

	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
}

static int	neg(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

int	getlen(int n)
{
	int	i;

	if (n == 0)
		return (2);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*s1;
	int		count;
	int		is_neg;

	count = 0;
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	s1 = ft_calloc(getlen(n) + is_neg, sizeof(*s1));
	if (s1 == 0)
		return (0);
	s1[0] = '0';
	while (n != 0)
	{
		s1[count++] = '0' + neg(n % 10);
		n = (n / 10);
	}
	if (is_neg == 1)
		s1[count] = '-';
	reverse(s1);
	return (s1);
}
