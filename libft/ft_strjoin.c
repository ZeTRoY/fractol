/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:48:32 by aroi              #+#    #+#             */
/*   Updated: 2018/06/22 19:39:48 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	len_of_str(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (len_of_str(s1) + len_of_str(s2) + 1));
	if (!str)
		return (0);
	if (s1)
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
	str[i + j] = '\0';
	return (str);
}
