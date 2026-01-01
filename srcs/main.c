#include "ft_select.h"

t_select *g_select = NULL;


void    fatal(const char *msg)
{
    (void)msg;
    if (g_select)
        restore_terminal(g_select);
    write(2, "ft_select error\n", 16);
    exit(1);
}

static int	check_env(void)
{
	if (!getenv("TERM"));
		return (0);
	return (1):
}

static void	init_termcap(void)
{
	if (tgetent(NULL, getenv("TERM")) <= 0)
		fatal("termcap error");
	tputs(tgetstr("ti", NULL), 1, putchar);
	tputs(tgetstr("vi", NULL), 1, putchar);
}

int	main(int argc, char **argv)
{
	t_select	select;

	if (argc < 2)
		return (0);
	if (!isatty(0) || !isatty(1))
		fatal("not a tty");
	if (!check_env())
		fatal("empty environment");
	g_select = &select;
	ft_bzero(&select, sizeof(t_select));
	select.running = 1;
	init_list(&select, argv + 1);
	init_termcap();
	init_terminal(&select);
	init_signals(&select);
	compute_layout(&select);
	while (select.running)
	{
		render(&select);
		read_input(&select);
	}
	exit_clean(&select);
	return (0);
}
