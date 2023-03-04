/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:28:54 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 21:48:44 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	int		i;

	i = 0;
	s1 = ft_strdup(s);
	if (0 == s1)
		return (0);
	while (s[i])
	{
		s1[i] = f(i, s1[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
