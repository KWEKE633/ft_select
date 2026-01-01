# NAME        = ft_select

# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror

# INCLUDES    = -Iincludes -Ilibft/includes
# LIBFT_DIR   = libft
# LIBFT       = $(LIBFT_DIR)/libft.a

# SRCS_DIR    = srcs
# OBJS_DIR    = objs

# SRCS        = $(SRCS_DIR)/main.c \
#               $(SRCS_DIR)/init_term.c \
#               $(SRCS_DIR)/restore_term.c \
#               $(SRCS_DIR)/exit_clean.c \
#               $(SRCS_DIR)/fatal.c \
#               $(SRCS_DIR)/list.c \
#               $(SRCS_DIR)/layout.c \
#               $(SRCS_DIR)/render.c \
#               $(SRCS_DIR)/input.c \
#               $(SRCS_DIR)/delete.c \
#               $(SRCS_DIR)/result.c \
#               $(SRCS_DIR)/signal.c \
#               $(SRCS_DIR)/cleanup.c \
#               $(SRCS_DIR)/slide.c \
#               $(SRCS_DIR)/colorize.c

# OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# all: $(LIBFT) $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -ltermcap -o $(NAME)

# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
# 	@mkdir -p $(OBJS_DIR)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# clean:
# 	$(MAKE) clean -C $(LIBFT_DIR)
# 	rm -rf $(OBJS_DIR)

# fclean: clean
# 	$(MAKE) fclean -C $(LIBFT_DIR)
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME        = ft_select

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -Iincludes

SRCS_DIR    = srcs
OBJS_DIR    = objs

SRCS        = $(SRCS_DIR)/main.c \
              $(SRCS_DIR)/init_term.c \
              $(SRCS_DIR)/restore_term.c \
              $(SRCS_DIR)/exit_clean.c \
              $(SRCS_DIR)/fatal.c \
              $(SRCS_DIR)/list.c \
              $(SRCS_DIR)/layout.c \
              $(SRCS_DIR)/render.c \
              $(SRCS_DIR)/input.c \
              $(SRCS_DIR)/delete.c \
              $(SRCS_DIR)/result.c \
              $(SRCS_DIR)/signal.c \
              $(SRCS_DIR)/cleanup.c \
              $(SRCS_DIR)/slide.c \
              $(SRCS_DIR)/colorize.c \
			  $(SRCS_DIR)/utils.c

OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -ltermcap -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
