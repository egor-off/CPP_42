NAME	= karenFilter

NAME_SRCS = main.cpp Karen.cpp

RM = rm -f

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

all: $(NAME)

$(NAME) : $(NAME_SRCS) Makefile
	@$(CC) $(FLAGS) $(NAME_SRCS) -o $(NAME)
	@printf "ex06 was build ✅\n"

clean:
		@printf "ALL is in trash 🗑\n"

fclean: clean
		@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re
