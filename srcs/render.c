#include "ft_select.h"

static void put_attr(t_item *it, t_item *cursor)
{
    if (it == cursor && it->selected)
    {
        tputs(tgetstr("us", NULL), 1, putchar);
        tputs(tgetstr("so", NULL), 1, putchar);
    }
    else if (it == cursor)
        tputs(tgetstr("us", NULL), 1, putchar);
    else if (it->selected)
        tputs(tgetstr("so", NULL), 1, putchar);
}

static void reset_attr(void)
{
    tputs(tgetstr("se", NULL), 1, putchar);
    tputs(tgetstr("ue", NULL), 1, putchar);
}

static void compute_xy(t_select *s, int index, int *x, int *y)
{
    int col;
    int row;
    int col_width;

    col_width = (s->term_width / s->col_count);
    col = (index / s->row_count) - s->col_offset;
    row = index % s->row_count;
    *x = col * col_width;
    *y = row;
}

static void render_search(t_select *s)
{
    if (s->search_len == 0)
        return ;
    reset_color();
    reset_attr();
    tputs(tgoto(tgetstr("cm", NULL), 0, s->term_height - 1), 1, putchar);
    write(1, "/", 1);
    write(1, s->search, s->search_len);
}

void    render(t_select *s)
{
    t_item  *it;
    int     i;
    int     x;
    int     y;

    tputs(tgetstr("cl", NULL), 1, putchar);
    if (s->col_count == 0 || s->row_count == 0)
    {
        reset_color();
        reset_attr();
        write(1, "Window too small", 16);
        return ;
    }
    update_col_offset(s);
    it = s->items;
    i = 0;
    while (i < s->count)
    {
        compute_xy(s, i, &x, &y);
        if (x >= 0)
        {
            tputs(tgoto(tgetstr("cm", NULL), x, y), 1, putchar);
            put_attr(it, s->cursor);
            put_color(it->name); 
            write(1, it->name, ft_strlen(it->name));
            reset_color(); 
            reset_attr();
        }
        it = it->next;
        i++;
    }
    reset_color();
    reset_attr();
    render_search(s);
}
