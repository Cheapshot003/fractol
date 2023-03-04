/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:14 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 21:45:01 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (0);
		set++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	acount;
	size_t	bcount;
	char	*s;

	acount = 0;
	bcount = ft_strlen(s1);
	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	while (inset(s1[acount], set) == 0)
		acount++;
	if (acount == ft_strlen(s1))
	{
		s = ft_strdup("");
		if (!(s))
			return (0);
		else
			return (s);
	}
	while (inset(s1[bcount - 1], set) == 0)
		bcount--;
	s = ft_substr(s1, acount, bcount - acount);
	return (s);
}
