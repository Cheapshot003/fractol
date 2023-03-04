/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <otietz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:19:39 by otietz            #+#    #+#             */
/*   Updated: 2022/10/13 22:11:54 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, int i, char c)
{
	int	wk;
	int	flag;

	wk = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c && !flag)
			flag = 1;
		else if (s[i] != c && flag)
		{
			flag = 0;
			wk++;
		}
		i++;
	}
	return (wk);
}

char	*helper1(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * ((int)(s1 - s2) + 1));
	while (s2 < s1)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**split1(char const *s, char c, char **arr, int k)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = -1;
	while (j < k)
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || j == k) && flag >= 0)
		{
			arr[j++] = helper1(&s[i], &s[flag]);
			flag = -42;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	char	**arr;
	int		k;

	if (!s)
		return (0);
	k = count(s, 0, c);
	arr = malloc((k + 1) * sizeof(char *));
	if (!arr)
		return (0);
	s1 = split1(s, c, arr, k);
	return (s1);
}
