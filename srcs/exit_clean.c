#include "ft_select.h"

void    exit_clean(t_select *s)
{
    t_item  *tmp;
    t_item  *next;

    clear_screen_exit(s);
    restore_terminal(s);

    tmp = s->items;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->name);
        free(tmp);
        tmp = next;
        if (tmp == s->items)
            break ;
    }
    exit(0);
}
