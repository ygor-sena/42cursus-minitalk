SERVER		=		server
CLIENT 		=		client
SRC			= 		server.c \
					client.c

LIBFT		= 		./libft/libft.a
SRCS_PATH	= 		src
OBJS_PATH	= 		obj
SRCS		= 		$(addprefix $(SRCS_PATH)/, $(SRC))
OBJS		= 		$(addprefix $(OBJS_PATH)/, $(SRC:.c=.o))

CC			= 		cc -Wall -Wextra -Werror
#-D_POSIX_C_SOURCE=199309L
RM			= 		rm -rf

all:				$(OBJS_PATH) $(LIBFT) $(OBJS)
					$(CC) $(addprefix $(OBJS_PATH)/, server.o) $(LIBFT) -o $(SERVER)
					$(CC) $(addprefix $(OBJS_PATH)/, client.o) $(LIBFT) -o $(CLIENT)

$(SERVER):			$(OBJS_PATH) $(LIBFT) $(OBJS)		
					$(CC) $(addprefix $(OBJS_PATH)/, server.o) $(LIBFT) -o $(SERVER)

$(CLIENT):			$(OBJS_PATH) $(LIBFT) $(OBJS)		
					$(CC) $(addprefix $(OBJS_PATH)/, client.o) $(LIBFT) -o $(CLIENT)
					
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