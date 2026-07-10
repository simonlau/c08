#include "ft_strs_to_tab.h"
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
	assert(av[0] == result[0].str);
	assert(av[0] != result[0].copy);
	assert(strcmp(av[0], result[0].copy) == 0);
}

int	main(void)
{
	test_invalid();
	test_one();
}
