#include "ft_select.h"

static t_item *new_item(char *name)
{
    t_item *item;

    item = (t_item *)malloc(sizeof(t_item));
    if (!item)
        fatal("malloc failed");
    item->name = ft_strdup(name);
    if (!item->name)
        fatal("malloc failed");
    item->selected = 0;
    item->prev = item;
    item->next = item;
    return (item);
}

static void push_back(t_select *s, t_item *item)
{
    t_item *last;

    if (!s->items)
    {
        s->items = item;
        s->cursor = item;
        return ;
    }
    last = s->items->prev;
    last->next = item;
    item->prev = last;
    item->next = s->items;
    s->items->prev = item;
}

void    init_list(t_select *s, char **av)
{
    int     i;
    t_item  *item;

    i = 0;
    s->items = NULL;
    s->count = 0;
    while (av[i])
    {
        item = new_item(av[i]);
        push_back(s, item);
        s->count++;
        i++;
    }
}
