#include "ft_stock_str.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void		ft_show_tab(t_stock_str *par);

enum
{
	READ_END,
	WRITE_END
};

typedef struct s_capture
{
	int		pipe_fds[2];
	int		stdout_backup;
	char	buf[1024];
	ssize_t	len;
}			t_capture;

void		ft_putstr(char *str);

void	setup(t_capture *c)
{
	c->stdout_backup = dup(STDOUT_FILENO);
	pipe(c->pipe_fds);
	dup2(c->pipe_fds[WRITE_END], STDOUT_FILENO);
}

void	teardown(t_capture *c)
{
	close(c->pipe_fds[WRITE_END]);
	dup2(c->stdout_backup, STDOUT_FILENO);
	c->len = read(c->pipe_fds[READ_END], c->buf, sizeof(c->buf) - 1);
	c->buf[c->len] = '\0';
	close(c->pipe_fds[READ_END]);
}

void	test_none(void)
{
	t_capture	c;
	t_stock_str	stocks[] = {{0, 0, 0}};

	setup(&c);
	ft_show_tab(stocks);
	teardown(&c);
	assert(0 == strcmp("", c.buf));
}

void	test_one(void)
{
	t_stock_str	stocks[] = {{.size = 2, .str = "me", .copy = "me2"}, {.size = 0,
			.str = 0, .copy = 0}};
	t_capture	c;

	setup(&c);
	ft_show_tab(stocks);
	teardown(&c);
	assert(0 == strcmp("me\n2\nme2\n", c.buf));
}

void	test_two(void)
{
	t_capture	c;
	t_stock_str	stocks[] = {{.size = 2, .str = "me", .copy = "me2"}, {.size = 3,
			.str = "you", .copy = "you2"}, {.size = 0, .str = 0, .copy = 0}};

	setup(&c);
	ft_show_tab(stocks);
	teardown(&c);
	assert(0 == strcmp("me\n2\nme2\nyou\n3\nyou2\n", c.buf));
}

int	main(void)
{
	test_none();
	test_one();
	test_two();
}
