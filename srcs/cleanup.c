#include "ft_select.h"

static void move_cursor_bottom(t_select *s)
{
    int y;

    y = s->term_height - 1;
    tputs(tgoto(tgetstr("cm", NULL), 0, y), 1, putchar);
}

void    clear_screen_exit(t_select *s)
{
    if (!s || s->col_count == 0)
        return ;

    move_cursor_bottom(s);
    tputs(tgetstr("cd", NULL), 1, putchar);
}
