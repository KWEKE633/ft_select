#include "ft_select.h"

void    restore_terminal(t_select *s)
{
    if (!s)
        return ;
    tcsetattr(0, TCSANOW, &s->old_term);
    tputs(tgetstr("ve", NULL), 1, putchar);
    tputs(tgetstr("te", NULL), 1, putchar);
}
