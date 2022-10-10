/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:18:30 by rmarquit          #+#    #+#             */
/*   Updated: 2021/10/25 20:03:27 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (w);
}

static void	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*ft_writeword(char	const *s, char c, char	**str1)
{
	int		i;
	char	*str;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (ft_free(str1));
	i = 0;
	while (*s && *s != c)
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		y;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	str = (char **)malloc(sizeof (char *) * (words + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (y < words)
	{
		str[y] = ft_writeword(s, c, str);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			s++;
		y++;
	}
	str[y] = NULL;
	return (str);
}
