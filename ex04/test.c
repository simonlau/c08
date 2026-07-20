#include "ft_stock_str.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	test_invalid(void)
{
	assert(NULL == ft_strs_to_tab(0, NULL));
}

void	test_one(void)
{
	char		*av[] = {"simon"};
	t_stock_str	*result;

	result = ft_strs_to_tab(1, av);
	assert(5 == result[0].size);
	assert(av[0] != result[0].str);
	assert(av[0] != result[0].copy);
	assert(strcmp(av[0], result[0].str) == 0);
	assert(strcmp(av[0], result[0].copy) == 0);
	free(result[0].str);
	free(result[0].copy);
	assert(0 == result[1].size);
	assert(0 == result[1].str);
	assert(0 == result[1].copy);
	free(result);
}

void	test_two(void)
{
	char		*av[] = {"simon", "lau"};
	t_stock_str	*result;

	result = ft_strs_to_tab(2, av);
	assert(5 == result[0].size);
	assert(av[0] != result[0].str);
	assert(av[0] != result[0].copy);
	assert(strcmp(av[0], result[0].str) == 0);
	assert(strcmp(av[0], result[0].copy) == 0);
	free(result[0].str);
	free(result[0].copy);
	assert(3 == result[1].size);
	assert(av[1] != result[1].str);
	assert(av[1] != result[1].copy);
	assert(strcmp(av[1], result[1].str) == 0);
	assert(strcmp(av[1], result[1].copy) == 0);
	free(result[1].str);
	free(result[1].copy);
	assert(0 == result[2].size);
	assert(0 == result[2].str);
	assert(0 == result[2].copy);
	free(result);
}

int	main(void)
{
	test_invalid();
	test_one();
	test_two();
}
