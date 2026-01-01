#include "ft_select.h"

#define C_RESET   "\033[0m"
#define C_BLUE    "\033[34m"
#define C_GREEN   "\033[32m"
#define C_CYAN    "\033[36m"

static const char *get_color(char *name)
{
    struct stat st;

    if (lstat(name, &st) == -1)
        return (C_RESET);
    if (S_ISDIR(st.st_mode))
        return (C_BLUE);
    if (S_ISLNK(st.st_mode))
        return (C_CYAN);
    if (st.st_mode & S_IXUSR)
        return (C_GREEN);
    return (C_RESET);
}

void    put_color(char *name)
{
    const char *color;

    color = get_color(name);
    write(1, color, ft_strlen(color));
}

void    reset_color(void)
{
    write(1, C_RESET, ft_strlen(C_RESET));
}
