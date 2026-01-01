#include "ft_select.h"

void    print_result(t_select *s)
{
    t_item  *it;
    int     first;

    it = s->items;
    first = 1;
    while (it)
    {
        if (it->selected)
        {
            if (!first)
                write(1, " ", 1);
            write(1, it->name, ft_strlen(it->name));
            first = 0;
        }
        it = it->next;
        if (it == s->items)
            break ;
    }
}
