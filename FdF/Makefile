DIRLIB = ./libft/

DIRINC = ./includes/

DIRSRC = ./srcs/

SRC =	main \
		read_file \
		utils \
		draw \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

NAME = fdf.a
NAMELIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -L -lmlx -lXext -lX11
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAMELIBFT):
	make all -C $(DIRLIB)
	make all -C ./minilibx/

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SRCS) minilibx/libmlx.a libft/libft.a -o fdf -I $(DIRINC)

bonus: $(NAMELIBFT)
#	...

clean:
	make clean -C $(DIRLIB)

fclean: clean
	make fclean -C $(DIRLIB)
	rm -f fdf

re: fclean all
