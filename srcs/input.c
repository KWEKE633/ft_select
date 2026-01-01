#include "ft_select.h"

static void reset_search(t_select *s)
{
    s->search_len = 0;
    ft_bzero(s->search, 256);
}

static int is_printable(char c)
{
    return (c >= 32 && c <= 126);
}

static void handle_arrow(t_select *s, char key)
{
    if (key == KEY_UP || key == KEY_LEFT)
        s->cursor = s->cursor->prev;
    else if (key == KEY_DOWN || key == KEY_RIGHT)
        s->cursor = s->cursor->next;
}

static void toggle_select(t_select *s)
{
    s->cursor->selected = !s->cursor->selected;
    s->cursor = s->cursor->next;
}

static void handle_key(t_select *s, char *buf)
{
    if (buf[0] == KEY_ESC && buf[1] == 0)
        exit_clean(s);
    if (buf[0] == KEY_ENTER)
    {
        restore_terminal(s);
        print_result(s);
        exit(0);
    }
    if (buf[0] == KEY_SPACE)
    {
        reset_search(s);
        toggle_select(s);
    }
    if (buf[0] == KEY_BACKSPACE || buf[0] == KEY_DELETE)
    {
        reset_search(s);
        delete_current(s);
    }
    if (buf[0] == KEY_ESC && buf[1] == '[')
    {
        reset_search(s);
        handle_arrow(s, buf[2]);
    }
    if (is_printable(buf[0]))
    {
        if (s->search_len < 255)
        {
            s->search[s->search_len++] = buf[0];
            search_move_cursor(s);
        }
    }
}

void    read_input(t_select *s)
{
    char buf[4];

    ft_bzero(buf, 4);
    if (read(0, buf, 3) <= 0)
        return ;
    handle_key(s, buf);
}
