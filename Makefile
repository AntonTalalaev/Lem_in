
NAME			:= lem-in

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

SRCDIR			:= ./sources/
OBJDIR			:= ./objects/
INCDIR			:= ./includes/

# .c files
FILES			:=	main.c \
					bfs.c \
					bfs2.c \
					bfs_helpers.c \
					decode_to_tab.c \
					decode_to_tab_helper.c \
					ft_matrix.c \
					ft_strchr_index.c \
					ft_arrdel.c \
					ft_parsing.c \
					ft_matrix_correcter.c \
					ft_var_parser.c \
					ft_get_final_sol.c \
					ft_ant_arr_creation.c \
					ft_final_print.c \
					ft_free_all.c \
					ft_matrix_correcter_start.c \
					ft_matrix_correcter_finish.c \
					ft_str_valid_cheker.c \
					ft_str_valid_cheker_tool.c \
					ft_list_of_rooms_creater.c \
					ft_adj_matrix_creater.c \
					ft_way_comparison_creater.c \
					ft_sol_creation.c \
					ft_printf_ants.c \
					ft_print_fin_ways.c \
					ft_print_flag_s_t.c \
					ft_print.c

OBJ				:= $(addprefix $(OBJDIR), $(FILES:%.c=%.o))

FT				:= ./libft
FT_LIB			:= $(addprefix $(FT),libft.a)
FT_INC			:= -I ./libft
FT_LNK			:= -L ./libft -l ft

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
