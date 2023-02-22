NAME = fdf.a

NAMELIBFT = libft/libft.a

NAMEMLX = minilibx/libmlx.a

DIRSRC = ./srcs/

LIBDIR = ./includes/

INC=/usr/includes/

INCLIB=$(INC)/../lib

CC = cc

CFLAGS = -I$(LIBDIR) -I/usr/include -O3 -g

LFLAGS = $(NAMELIBFT) $(NAMEMLX) -L$(INCLIB) -lXext -lX11 -lm -lbsd

MLX_FLAGS = $(NAMEMLX) -L -lmlx -lXext -lX11

SRC =	main \
		read_file \
		utils \
		draw \
		keys \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(NAMELIBFT) $(NAMEMLX)
	$(CC) -o fdf $(OBJS) $(LFLAGS)
	@echo "Compiled $@"

$(NAMELIBFT):
	@make all -s -C ./libft
	@echo "Compiled $@"

$(NAMEMLX):
	@make all -s -C ./minilibx
	@echo "Compiled $@"

# bonus:
# 	make all -C ./libft
# 	$(CC) -g $(CFLAGS) $(SRC_C_BONUS) $(NAMELIBFT) -o checker

clean:
	@rm -rf $(OBJS)
	@make -s -C ./libft clean
	@make -s -C ./minilibx clean
	@echo "Remove objects files."

fclean: clean
	@make -s -C ./libft fclean
	@make -s -C ./minilibx clean
	@rm -rf fdf
	@echo "Remove static libraries and executables."

re: fclean all
