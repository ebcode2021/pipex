# VARIABLE
NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcus

RM = rm -rf

# PIPEX
SRCS = pipex.c pipex_utils.c pipex_error.c pipex_parser.c
SRCS_DIR = srcs/pipex/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# GNL
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_DIR = srcs/get_next_line/
GNL_PATH = $(addprefix $(GNL_DIR), $(GNL_SRCS))

# LIBFT
LIBFT_DIR = srcs/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

INCS = includes
OBJS = $(SRCS_PATH:.c=.o)
GNL_OBJS = $(GNL_PATH:.c=.o)

# COMMANDS
%.o : %.c
	@echo "$(YELLOW) *** Generating pipex objects... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(GNL_DIR) -I$(LIBFT_DIR)

$(NAME) : $(OBJS) $(GNL_OBJS)
	@echo "$(GREEN) *** Compiling pipex with bonuses... *** $(DEFAULT)"
	make -j -C srcs/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_OBJS) $(LIBFT_A)
	@echo "$(GREEN) *** Compile Done! *** $(DEFAULT)"

all : $(NAME)

clean :
	@echo "$(RED) *** Deleting objects... ***$(DEFAULT)"
	$(RM) $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	@echo "$(RED) Deleting executable...$(DEFAULT)"
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m