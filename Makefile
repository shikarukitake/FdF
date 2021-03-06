NAME_1 = fdf

NAME_2 = fdf_debug
LIBFT_A = libftprintf.a

SR_LI_1 =	main.c \
			read_file.c \
			service.c \
			draw.c \
			bresenham.c \
			check.c \

SOURCES_DIR = ./general/srcs/

SRCS_LI_1 = $(addprefix $(SOURCES_DIR), $(SR_LI_1))
OBJECT_DIR_1 = objects1/
OBJ_LIST_LI_1 = $(patsubst %.c, %.o, $(SR_LI_1))
OBJ_LI_1 = $(addprefix $(OBJECT_DIR_1), $(OBJ_LIST_LI_1))

HEADER_DIR = ./general/includes/

# ft_printf
#OBJECT_PF = ./ft_printf/objects
#
LIB_MLX = minilibx/libmlx.a
LIBS_MLX = -L./ft_printf -lftprintf
MLX_DIR = ./minilibx

COMPILER := gcc
HDRPATH := ./general/includes -I./general/libftprintf/includes -I./minilibx
IFLAGS := -I$(HDRPATH)
CFLAGS := -Wall -Wextra -Werror -g

LIB_DIR = ./general/libftprintf
LIB_RULE = $(addsuffix .lib, $(LIB_DIR))

LIBFT = ./general/libftprintf/libftprintf.a
LIBS = -L./general/ft_libftprintf -l_ftprintf


all: $(LIB_RULE) $(NAME_1)

%.lib:
	@$(MAKE) -sC $(LIB_DIR)

$(NAME_1): $(LIBFT) $(LIB_MLX) $(OBJECT_DIR_1) $(OBJ_LI_1)
	@$(COMPILER) $(CFLAGS) $(IFLAGS) $(LIBFT) $(LIB_MLX) $(OBJ_LI_1) -o $(NAME_1) -framework OpenGL -framework AppKit

$(OBJECT_DIR_1):
	@mkdir -p $(OBJECT_DIR_1)

$(OBJECT_DIR_1)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(COMPILER) $(CFLAGS) -c $(IFLAGS) $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

$(LIB_MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJECT_DIR_1)
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJECT_PF)
	@make -C $(MLX_DIR) clean

fclean: clean
	@make -C $(LIB_DIR) fclean
	@/bin/rm -f $(NAME_1)

re: fclean all
