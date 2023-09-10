SRC = 		error.c \
			free_file.c \
			little_cool_function/little_cool_function.c \
			little_cool_function/little_cool_function_1.c \
			little_cool_function/little_cool_function_2.c \
			main.c \
			parsing/parsing.c \
			parsing/parsing_1.c \
			parsing/parsing_2.c \
			parsing/parsing_3.c \
			gen_file/gen_file.c \
			gen_file/gen_file_1.c \
			gen_file/gen_file_2.c \
			save.c \
			set_null.c \
			normal_vec.c \
			vector/vector.c \
			vector/vector_1.c \
			color/color.c \
			color/color_1.c \
			color/color_2.c \
			mlx/motion/mouvement_light.c \
			mlx/motion/mouvement_triangle.c \
			mlx/motion/mouvement_cylinder.c \
			mlx/motion/mouvement_square.c \
			mlx/motion/mouvement_plane.c \
			mlx/motion/mouvement_sphere.c \
			mlx/motion/mouvement_cam.c \
			mlx/init/mlx_init.c \
			mlx/init/mlx_init_1.c \
			mlx/init/mlx_init_2.c \
			mlx/init/mlx_init_3.c \
			src/cylinder.c \
			src/plane.c \
			src/sphere.c \
			src/triangle.c \
			src/square.c \

OBJS = $(SRC:.c=.o)

NAME = miniRT

CC = clang

CFLAGS = -Wall -Wextra -Werror -I./
CFLAGS2 = -I./minilibx -I/usr/include -I ./ -L./ -lft -lXext -lX11 -lbsd -L./minilibx -lm -lmlx
RM = rm -rf

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C minilibx
	make -C libft
	mv libft/libft.a ./libft.a
	$(CC) -g3 -o $(NAME) $(OBJS) $(CFLAGS2)

all: $(NAME)

clean:
	$(RM) libft.a
	$(RM) $(OBJS)
	make -C minilibx -f Makefile clean
	make -C libft -f Makefile clean

fclean: clean
	$(RM) $(NAME)
	make -C libft -f Makefile fclean

re: fclean all

.PHONY: all clean fclean re
