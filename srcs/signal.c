#include "ft_select.h"

static void sig_winch(int sig)
{
    (void)sig;
    if (!g_select)
        return ;
    compute_layout(g_select);
    render(g_select);
}

static void sig_tstp(int sig)
{
    (void)sig;
    if (!g_select)
        return ;
    restore_terminal(g_select);
    signal(SIGTSTP, SIG_DFL);
    kill(0, SIGTSTP);
}

static void sig_cont(int sig)
{
    (void)sig;
    if (!g_select)
        return ;
    init_terminal(g_select);
    signal(SIGTSTP, sig_tstp);
    render(g_select);
}

static void sig_exit(int sig)
{
    (void)sig;
    exit_clean(g_select);
}

void    init_signals(t_select *s)
{
    g_select = s;
    signal(SIGWINCH, sig_winch);
    signal(SIGTSTP, sig_tstp);
    signal(SIGCONT, sig_cont);
    signal(SIGINT, sig_exit);
    signal(SIGTERM, sig_exit);
}
