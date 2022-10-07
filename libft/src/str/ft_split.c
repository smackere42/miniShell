/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:31:54 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/07 02:59:07 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		words++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (words);
}

static int	ft_split_word_len(const char *s, char c)
{
	int	j;

	j = 0;
	while (*(s + j) != c && *(s + j))
		j++;
	return (j + 1);
}

static void	*ft_split_free(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
	return ((void *)0);
}

int	ft_split_len(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**tmp;	
	int		words;
	int		len_word;
	int		i;

	if (s == ((void *)0))
		return ((void *)0);
	words = ft_split_words(s, c);
	tmp = (char **)malloc((words + 1) * sizeof(char *));
	if (!tmp)
		return ((void *)0);
	tmp[words] = ((void *)0);
	i = -1;
	while (++i < words)
	{
		while (*s == c && *s)
			s++;
		len_word = ft_split_word_len(s, c);
		tmp[i] = (char *)malloc(len_word * sizeof(char));
		if (!tmp[i])
			return (ft_split_free(tmp));
		ft_strlcpy(tmp[i], s, len_word);
		s += len_word;
	}
	return (tmp);
}
