/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:58 by hgicquel          #+#    #+#             */
/*   Updated: 2021/07/11 16:44:59 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// #include <unistd.h>
// #include <stdio.h>

int	ft_include(char	*str, int l, char c)
{
	int	i;

	i = 0;
	while (i < l && str[i] != c)
		i++;
	if (i == l)
		return (0);
	return (1);
}

int	ft_count(char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		while (str[i] && ft_include(charset, l, str[i]))
			i++;
		j = 0;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
			j++;
		if (j)
			s++;
		i += j;
	}
	return (s);
}

void	ft_alloc(char **strs, char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		while (str[i] && ft_include(charset, l, str[i]))
			i++;
		j = 0;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
			j++;
		if (j)
			strs[s++] = malloc((j + 1) * sizeof(char));
		i += j;
	}
	strs[s] = 0;
}

void	ft_fill(char **strs, char *str, char *charset, int l)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		while (str[i] && ft_include(charset, l, str[i]))
			i++;
		j = 0;
		while (str[i + j] && !ft_include(charset, l, str[i + j]))
		{
			strs[s][j] = str[i + j];
			j++;
		}
		if (j)
			strs[s++][j] = '\0';
		i += j;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		l;
	int		s;
	char	**strs;

	l = 0;
	while (charset[l])
		l++;
	s = ft_count(str, charset, l);
	strs = malloc((s + 1) * sizeof(char *));
	ft_alloc(strs, str, charset, l);
	ft_fill(strs, str, charset, l);
	return (strs);
}

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	int		j;
// 	char	**strs;

// 	if (argc != 3)
// 		return (1);
// 	strs = ft_split(argv[1], argv[2]);
// 	i = 0;
// 	while (strs[i])
// 	{
// 		j = 0;
// 		while (strs[i][j])
// 			j++;
// 		write(1, strs[i], j);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }
