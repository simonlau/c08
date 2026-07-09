#include "ft_strs_to_tab.h"
#include <assert.h>
#include <stdlib.h>

struct t_stock_str	*ft_strs_to_tab(int ac, char **av);

void	test_invalid(void)
{
	assert(NULL == ft_strs_to_tab(0, NULL));
}

int	main(void)
{
	test_invalid();
}
