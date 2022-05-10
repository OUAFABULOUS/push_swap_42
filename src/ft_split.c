/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:47:34 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/11 00:04:26 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static int	ft_char_in_charset(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_word_count(char const *str, char *charset)
{
	int	i;
	int	sep;
	int	word_count;

	i = 0;
	sep = 1;
	word_count = 0;
	while (str[i])
	{
		if (ft_char_in_charset(charset, str[i]))
			sep = 1;
		if (sep == 1 && !ft_char_in_charset(charset, str[i]))
		{
			word_count += 1;
			sep = 0;
		}
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		word_count;
	char	**tab;

	i = 0;
	j = 0;
	k = -1;
	word_count = ft_word_count(str, charset);
	tab = malloc ((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (++k < word_count)
	{
		while (str[i] && ft_char_in_charset(charset, str[i]))
			i++;
		j = i;
		while (str[i] && !ft_char_in_charset(charset, str[i]))
			i++;
		tab[k] = malloc ((i - j + 1) * sizeof(char));
		tab[k] = ft_strncpy((char *)tab[k], str + j, i - j + 1);
	}
	tab[k] = NULL;
	return (tab);
}
