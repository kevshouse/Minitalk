SERVER = server_exec
CLIENT = client_exec
LIBFT = inc/libft/libft.a

CC = gcc
INCS = -Iserver -Iclient -Iinc
CFLAGS = -Wall -Wextra -Werror $(INCS)

# Server sources
SSRCS = server/main.c server/sig_handler.c server/server_logic.c

# Client sources
CSRCS = client/main.c client/bit_tx.c

# Test configuration
TEST_SRCS = tests/test_server.c tests/test_client.c client/bit_tx.c server/server_logic.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_LDFLAGS = -lcriterion -Wl,--wrap=kill

test: $(TEST_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFT) $(TEST_LDFLAGS) -o test_runner
	./test_runner

# Object files
SOBJS = $(SSRCS:.c=.o)
COBJS = $(CSRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	make -C inc/libft

$(SERVER): $(SOBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SOBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(COBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(COBJS) $(LIBFT) -o $(CLIENT)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SOBJS) $(COBJS) $(TEST_OBJS)
	make -C inc/libft clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) test_runner
	make -C inc/libft fclean

re: fclean all

.PHONY: all clean fclean re test
