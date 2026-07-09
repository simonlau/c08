/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 22:57:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/09 23:03:59 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strs_to_tab.h"
#include <stdlib.h>

static int	str_len(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

static char	*copy_str(char *str)
{
	int		len;
	char	*result;

	len = str_len(str);
	result = malloc(sizeof(char) * len);
	if (result)
	{
		return (NULL);
	}
	while (len > 0)
	{
		*result = *str;
		len--;
	}
	return (result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	if (ac < 1)
	{
		return (NULL);
	}
	result = malloc(ac * sizeof(t_stock_str));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (i < ac)
	{
		result[i].size = str_len(av[i]);
		result[i].str = av[i];
		result[i].copy = copy_str(av[i]);
		i++;
	}
	return (result);
}
