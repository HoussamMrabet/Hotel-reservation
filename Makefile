NAME = hotel

SRCS = main.c parser.c data.c ft_itoa.c ft_split.c get_next_line_bonus.c get_next_line_utils_bonus.c utils.c

OBJS = $(SRCS:.c=.o)

CC = @cc
# CFLAGS = -Wall -Wextra -Werror

RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)hotel program generated ✅$(RESET)"

$(OBJS): %.o: %.c
	$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)cleaning hotel objects! 🧹✨$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)remove hotel program ❌$(RESET)"

re: fclean all

.PHONY: clean