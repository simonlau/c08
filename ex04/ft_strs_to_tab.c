/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 22:57:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/10 10:03:43 by simon.lau        ###   ########.fr       */
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
	char	*buffer;
	char	*current_letter;

	len = str_len(str);
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
	{
		return (NULL);
	}
	current_letter = buffer;
	while (len > 0)
	{
		*current_letter = *str;
		current_letter++;
		str++;
		len--;
	}
	return (buffer);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
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
