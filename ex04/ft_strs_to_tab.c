/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 22:57:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/07/20 10:05:47 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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
	int		i;
	char	*buffer;
	char	*current_letter;

	len = str_len(str);
	buffer = malloc(sizeof(*buffer) * (len + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	current_letter = buffer;
	i = 0;
	while (i < len)
	{
		current_letter[i] = str[i];
		i++;
	}
	current_letter[i] = '\0';
	return (buffer);
}

static void	free_existing_result(t_stock_str *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i].copy != NULL)
		{
			free(arr[i].copy);
		}
		if (arr[i].str != NULL)
		{
			free(arr[i].str);
		}
		i++;
	}
	free(arr);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	if (ac < 1)
		return (NULL);
	result = malloc((ac + 1) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = str_len(av[i]);
		result[i].str = copy_str(av[i]);
		result[i].copy = copy_str(av[i]);
		if (av[i] != NULL && (result[i].copy == NULL || result[i].str == NULL))
		{
			free_existing_result(result, i);
			return (NULL);
		}
		i++;
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}
