SERVER		= server
CLIENT		= client

FLAGS			= -Wall -Wextra -Werror
OPT				= -O3 -flto -Ofast -ffast-math -march=native
LIBFT			= -L libft -lft

OBJS_DIR		= objects
INCLUDES		= includes
LIBFT_PATH		= libft

SRCS_SERVER		= \
				server.c
SRCS_CLIENT		= \
				client.c

FILES			= sources
FOLDERS			=
OBJS_SERVER		= $(addprefix $(OBJS_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT		= $(addprefix $(OBJS_DIR)/, $(SRCS_CLIENT:.c=.o))

all:				libs $(SERVER) $(CLIENT)

libs:
						@make -C ./libft

$(SERVER):			$(OBJS_SERVER)
						@mkdir -p $(OBJS_DIR)
						@gcc $(FLAGS) $(LIBFT) $^ -o $@
						@printf "\033[2K\r$(BLUE)$(SERVER)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

$(CLIENT):			$(OBJS_CLIENT)
						@gcc $(FLAGS) $(LIBFT) $^ -o $@
						@printf "\033[2K\r$(BLUE)$(CLIENT)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

$(OBJS_DIR)/%.o:	$(FILES)/%.c $(addprefix $(INCLUDES)/, minitalk.h) $(LIBFT_PATH)/libft.a
						@mkdir -p $(OBJS_DIR)
						@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@
						@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

clean:
						@rm -f $(OBJS_SERVER)
						@rm -f $(OBJS_CLIENT)
						@rm -rf $(OBJS_DIR)
						@make -C $(LIBFT_PATH) clean

fclean:				clean
						@rm -f $(SERVER)
						@rm -f $(CLIENT)
						@make -C $(LIBFT_PATH) fclean

re:					fclean all

.PHONY:				all clean fclean re

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m
