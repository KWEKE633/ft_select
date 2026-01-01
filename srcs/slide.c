#include "ft_select.h"

static int get_cursor_index(t_select *s)
{
    t_item  *it;
    int     i;

    it = s->items;
    i = 0;
    while (it)
    {
        if (it == s->cursor)
            return (i);
        it = it->next;
        i++;
        if (it == s->items)
            break ;
    }
    return (0);
}

void    update_col_offset(t_select *s)
{
    int cursor_index;
    int cursor_col;

    if (s->row_count == 0)
        return ;

    cursor_index = get_cursor_index(s);
    cursor_col = cursor_index / s->row_count;

    if (cursor_col < s->col_offset)
        s->col_offset = cursor_col;
    else if (cursor_col >= s->col_offset + s->col_count)
        s->col_offset = cursor_col - s->col_count + 1;
}
