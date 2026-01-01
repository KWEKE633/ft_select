#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <term.h>
# include <sys/stat.h>

#define KEY_ESC        27
#define KEY_ENTER      10
#define KEY_SPACE      32
#define KEY_BACKSPACE  127
#define KEY_DELETE     126

#define KEY_UP         65
#define KEY_DOWN       66
#define KEY_LEFT       68
#define KEY_RIGHT      67


typedef struct      s_item
{
    char            *name;
    int             selected;
    struct s_item   *next;
    struct s_item   *prev;
}                   t_item;

typedef struct s_select
{
    t_item          *items;
    t_item          *cursor;
    int             count;
    int             term_width;
    int             term_height;
    int             col_count;
    int             row_count;
    int             col_offset;
    char            search[256];
    int             search_len;
    int             running;
    struct termios  old_term;
}   t_select;

/* main */
void    fatal(const char *msg);

/* term */
void    init_terminal(t_select *s);
void    restore_terminal(t_select *s);

/* list */
void    init_list(t_select *s, char **av);

/* render */
void    render(t_select *s);

/* input */
void    read_input(t_select *s);

/* signal */
void    init_signals(t_select *s);

/* layout */
void    compute_layout(t_select *s);

/* exit */
void    exit_clean(t_select *s);

/* bonus cleanup */
void    clear_screen_exit(t_select *s);

/* bonus color */
void    put_color(char *name);
void    reset_color(void);


extern t_select *g_select;

#endif
