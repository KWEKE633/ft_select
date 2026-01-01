#include "ft_select.h"

static int  max_item_len(t_select *s)
{
    t_item  *it;
    int     max;
    int     len;

    it = s->items;
    max = 0;
    if (!it)
        return (0);
    while (1)
    {
        len = ft_strlen(it->name);
        if (len > max)
            max = len;
        it = it->next;
        if (it == s->items)
            break ;
    }
    return (max);
}

static void get_term_size(t_select *s)
{
    struct winsize ws;

    if (ioctl(0, TIOCGWINSZ, &ws) == -1)
        return ;
    s->term_width = ws.ws_col;
    s->term_height = ws.ws_row;
}

void    compute_layout(t_select *s)
{
    int max_len;
    int col_width;

    get_term_size(s);
    max_len = max_item_len(s);
    col_width = max_len + 1;
    s->col_offset = 0;  

    if (col_width == 0 || s->term_width < col_width)
    {
        s->col_count = 0;
        s->row_count = 0;
        return ;
    }

    s->row_count = s->term_height;
    s->col_count = s->term_width / col_width;

    if (s->col_count * s->row_count < s->count)
    {
        s->col_count = 0;
        s->row_count = 0;
    }
}
