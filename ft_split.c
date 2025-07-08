/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:15:45 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/05 19:34:09 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (s[i] != c && s[i] != '\0')
	{
		w++;
		i++;
	}
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c && s[i - 1] == c)
		{
			w++;
			i++;
		}
		else
			i++;
	}
	return (w);
}

static int	ft_size_word(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] == c && s[i] != '\0')
	{
		i++;
	}
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_free_mem(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		size = ft_size_word((s + i), c);
		result[j] = ft_substr((s + i), 0, size);
		if (!result[j])
			return (ft_free_mem(result, j));
		j++;
		i += size;
	}
	result[j] = 0;
	return (result);
}
/*
int	main(void)
{
	const char *s = "^^^1^^2a,^^^^3^^^^--h^^^^";
	char c = '^';
	char **res = ft_split(s, c);
	int i = 0;
	while (i < ft_count_words(s, c))
	{
		ft_putendl_fd(res[i], 1);
		i++;
	}
	ft_free_mem(res, 4);
	return (0);
}*/
