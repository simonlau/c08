#include "ft_stock_str.h"
#include <unistd.h>

static void	write_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

static void	write_positive_num(int num)
{
	char	digit;

	if (num < 0)
	{
		return ;
	}
	if (num < 10)
	{
		digit = num + '0';
		write(1, &digit, 1);
		return ;
	}
	write_positive_num(num / 10);
	digit = '0' + num % 10;
	write(1, &digit, 1);
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par != NULL && par[i].str != 0)
	{
		write_str(par[i].str);
		write(1, "\n", 1);
		write_positive_num(par[i].size);
		write(1, "\n", 1);
		write_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
