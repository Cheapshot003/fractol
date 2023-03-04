/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:16:26 by otietz            #+#    #+#             */
/*   Updated: 2022/10/20 23:19:47 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (0);
	s = s + start;
	s1 = malloc(len + 1);
	if (s1 == 0)
		return (0);
	ft_memcpy(s1, s, len);
	s1 += len;
	*s1 = '\0';
	return (s1 - len);
}
