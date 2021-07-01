#	Names
NAME_SERVER		=	server
NAME_CLIENT		=	client

#	Colors
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

#	Compilation
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto -march=native -ffast-math

LIBFT_PATH		=	./libft
INCLUDES_PATH	=	./includes


INCLUDE			=	./includes/minitalk.h
SERVER_SOURCES	=	./sources/server/server.c
CLIENT_SOURCES	=	./sources/client/client.c

SERVER_OBJS		=	$(SERVER_SOURCES:.c=.o)
CLIENT_OBJS		=	$(CLIENT_SOURCES:.c=.o)

#	Delete
RM				=	rm -f

#	Rules
#	Default rule
all:	$(NAME_SERVER) $(NAME_CLIENT)

#	How to convert .c in .o
%.o:	%.c $(LIBFT_PATH)/libft.a $(INCLUDES) $(LIBFT_PATH)/libft.h
	@$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@
	@printf "\033[2K\r$(BLUE)$(NAME_SERVER)/$(NAME_CLIENT)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

#	Compile libft.a
$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

#	Compile server program
$(NAME_SERVER):	$(LIBFT_PATH)/libft.a $(INCLUDES) $(SERVER_OBJS)
	@$(GCC) $(LIBFT_PATH)/libft.a $(FLAGS) -I $(INCLUDES_PATH) $(SERVER_OBJS) -o $(NAME_SERVER)
	@printf "\033[2K\r$(BLUE)$(NAME_SERVER)$(RESET)$(BLUEE): $(GREEN)Compiled [√]$(RESET)\n"

#	Compile client program
$(NAME_CLIENT):	$(LIBFT_PATH)/libft.a $(INCLUDES) $(CLIENT_OBJS)
	@$(GCC) $(LIBFT_PATH)/libft.a $(FLAGS) -I $(INCLUDES_PATH) $(CLIENT_OBJS) -o $(NAME_CLIENT)
	@printf "\033[2K\r$(BLUE)$(NAME_CLIENT)$(RESET)$(BLUEE): $(GREEN)Compiled [√]$(RESET)\n"

#	Clean project
#	Clean
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@printf "$(BLUE)$(NAME_SERVER)/$(NAME_CLIENT): $(LIGHT_RED)Cleaning all .o in project.\n$(RESET)"
#	Full clean
fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@printf "$(BLUE)$(NAME_SERVER)/$(NAME_CLIENT): $(RED)Cleaning compiled programs $(NAME_SERVER)/$(NAME_CLIENT).\n$(RESET)"

#	Recompile all
re:		fclean all

PHONY: all %.o clean fclean re norminette end gmk