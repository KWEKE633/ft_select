#include "ft_select.h"

void    delete_current(t_select *s)
{
    t_item *del;

    if (!s || !s->cursor)
        return ;
    if (s->count == 1)
        exit_clean(s);

    del = s->cursor;
    del->prev->next = del->next;
    del->next->prev = del->prev;

    if (s->items == del)
        s->items = del->next;

    s->cursor = del->next;
    free(del->name);
    free(del);
    s->count--;
}
