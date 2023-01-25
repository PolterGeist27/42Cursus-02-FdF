DIRLIB = ./libft/

DIRINC = ./includes/

DIRSRC = ./srcs/

SRC =	

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

NAME = fdf.a
NAMELIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(DIRINC)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAMELIBFT):
	make all -C $(DIRLIB)

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o fdf

bonus: $(NAMELIBFT)
#	...

clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
	rm -f fdf

re: fclean all