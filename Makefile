NAME 		=		minitalk
SERVER		=		server
CLIENT 		=		client
SRC			= 		server.c \
					client.c \
					wrapper.c

LIBFT		= 		./libft/libft.a
SRCS_PATH	= 		src
OBJS_PATH	= 		obj
SRCS		= 		$(addprefix $(SRCS_PATH)/, $(SRC))
OBJS		= 		$(addprefix $(OBJS_PATH)/, $(SRC:.c=.o))

CC			= 		cc -Wall -Wextra -Werror
RM			= 		rm -rf

all:				$(NAME) 

$(NAME):			$(OBJS_PATH) $(LIBFT) $(OBJS) $(SERVER) $(CLIENT)			


$(SERVER):			$(OBJS_PATH) $(LIBFT) $(OBJS)
					$(CC) $(addprefix $(OBJS_PATH)/, server.o) \
						$(addprefix $(OBJS_PATH)/, wrapper.o) $(LIBFT) -o $(SERVER)

$(CLIENT):			$(OBJS_PATH) $(LIBFT) $(OBJS)	
					$(CC) $(addprefix $(OBJS_PATH)/, client.o) \
						$(addprefix $(OBJS_PATH)/, wrapper.o) $(LIBFT) -o $(CLIENT)
					
$(OBJS_PATH):
					mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) -c $< -o $@

$(LIBFT):
					make -C ./libft

clean:
					$(RM) $(OBJS_PATH)

fclean:				clean
					make fclean -C ./libft
					$(RM) $(SERVER) $(CLIENT)

re:					fclean all

.PHONY:				all clean fclean re