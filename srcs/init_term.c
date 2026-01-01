#include "ft_select.h"

void    init_terminal(t_select *s)
{
    struct termios  term;

    if (tcgetattr(0, &s->old_term) == -1)
        fatal("tcgetattr failed");
    term = s->old_term;
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &term) == -1)
        fatal("tcsetattr failed");
}
