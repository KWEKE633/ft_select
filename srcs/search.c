#include "ft_select.h"

static int match(char *name, char *search, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (!name[i] || name[i] != search[i])
            return (0);
        i++;
    }
    return (1);
}

void    search_move_cursor(t_select *s)
{
    t_item *it;

    if (s->search_len == 0)
        return ;
    it = s->items;
    while (it)
    {
        if (match(it->name, s->search, s->search_len))
        {
            s->cursor = it;
            return ;
        }
        it = it->next;
        if (it == s->items)
            break ;
    }
}
