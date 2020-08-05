NAME_1 = fdf

NAME_2 = push_swap
LIBFT_A = libftprintf.a

SR_LI_1 =	main.c \
			read_file.c \
			service.c \

SOURCES_DIR = ./general/srcs/

SRCS_LI_1 = $(addprefix $(SOURCES_DIR), $(SR_LI_1))
OBJECT_DIR_1 = objects1/
OBJ_LIST_LI_1 = $(patsubst %.c, %.o, $(SR_LI_1))
OBJ_LI_1 = $(addprefix $(OBJECT_DIR_1), $(OBJ_LIST_LI_1))

HEADER_DIR = ./general/includes/

# ft_printf
#OBJECT_PF = ./ft_printf/objects
#
#LIB_PF = ft_printf/libftprintf.a
#LIBS_PF = -L./ft_printf -lftprintf
# --------

COMPILER := gcc
HDRPATH := ./general/includes -I./general/libftprintf/includes
IFLAGS := -I$(HDRPATH)
CFLAGS := -Wall -Wextra -Werror

LIB_DIR = ./general/libftprintf

LIBFT = ./general/libftprintf/libftprintf.a
LIBS = -L./general/ft_libftprintf -l_ftprintf


all: $(NAME_1)

$(NAME_1): $(LIBFT) $(LIB_PF) $(OBJECT_DIR_1) $(OBJ_LI_1)
	@$(COMPILER) $(CFLAGS) $(IFLAGS) $(LIBFT) $(LIBS_PF) $(OBJ_LI_1) -o $(NAME_1)

$(OBJECT_DIR_1):
	@mkdir -p $(OBJECT_DIR_1)

$(OBJECT_DIR_1)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(COMPILER) $(CFLAGS) -c $(IFLAGS) $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJECT_DIR_1)
	@make -C $(LIB_DIR) clean
#	@make -C ./ft_printf clean
	@rm -rf $(OBJECT_PF)

fclean: clean
	@make -C $(LIB_DIR) fclean
#	@make -C ./ft_printf fclean
	@/bin/rm -f $(NAME_1)

re: fclean all
