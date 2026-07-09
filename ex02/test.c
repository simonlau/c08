#include "ft.abs.h"
#include <assert.h>

int	main(void)
{
	assert(0 == (ABS(0)));
	assert(42 == (ABS(42)));
	assert(42 == (ABS(-42)));
}
