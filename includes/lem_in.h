/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:42:48 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/05 17:58:49 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "queue.h"
# include <fcntl.h>
# include "matrix.h"
# include <stdint.h>

# define FLAGS "fcoswar"

/*
**		n_links - number of links of the room
*/
typedef struct	s_room_name
{
	char			*name;
	int				x;
	int				y;
	int				n_links;
}				t_room_name;

/*
**		src - input
**		n_* - number of ants, rooms, links
**		list_of_rooms - to store list of rooms, index of room
**			is equal to it's index in adj_matrix
**		adj_matrix - to store adjacency matrix
**		rooms - our rooms structs
**		visual_src - to store input to visualisation (in what format?)
**		n_var - to store max number of var that we need
**		var - to store indexses of rooms
*/

typedef struct	s_pinfo
{
	int32_t			**tab;
	int32_t			value;
	int32_t			i_cur;
	int32_t			i_start;
	int32_t			i_last;
	int32_t			i_finished;
	int32_t			valid;
}				t_pinfo;

typedef struct	s_tqt
{
	t_queue			*res;
	t_queue			*lev;
	t_matrix		*rooms;
	int32_t			index;
	int32_t			var;
	int32_t			elem;
	int32_t			n_rooms;
}				t_tqt;

typedef struct	s_solution
{
	int				weight;
	int				len;
	int				n_ways;
	int				*adr;

}				t_solution;

typedef struct	s_ant
{
	int				*way;
	int				step;
}				t_ant;

typedef struct	s_fin_sol
{
	int				**base_way;
	int				n_ways;
	t_ant			*ant;
}				t_fin_sol;

typedef struct	s_lem
{
	char			*src;
	int				n_ants;
	int				n_rooms;
	int				n_var;
	int				n_start;
	int				n_finish;
	t_room_name		*list_of_rooms;
	char			**adj_matrix;
	int32_t			status;
	int32_t			flags;
	int				num_of_way;
	int				max_num_of_way;
	char			*way_cheker;
	char			*z_checker;
	int				fill_cheker;
	t_solution		*sol;
	t_fin_sol		fin_sol;
}				t_lem;

/*
** links - to store all links of the room
** index - index in lem.list_of_rooms: 0 is start, 1 is end
*/
typedef struct	s_room
{
	int				parent;
	int				next;
	int				step;
	int				index;
	char			*links;
}				t_room;

typedef struct	s_var_tab
{
	int32_t		**tab;
	int32_t		size_y;
	int32_t		size_x;
	int32_t		var;
}				t_var_tab;

/*
**		lem_in.h *
*/
/*
**		bfs_helpers.c
*/
int32_t			next_start(t_matrix *rooms, int32_t from);
void			duopush(t_tqt *q, int32_t n);
int32_t			deadlock(t_tqt *q, int32_t value);
int32_t			check_room(int32_t *rooms, int32_t cur, int32_t prew);
/*
**		bfs.c
*/
int32_t			encode_vars(t_lem *l);
/*
**		bfs2.c
*/
int32_t			check_elem(t_tqt *q);
/*
**		decode_to_tab.c *
*/
int32_t			**decode_to_tab(t_tqt *q);
/*
**		decode_to_tab_helper.c *
*/
int32_t			flag1(t_tqt *q, t_pinfo *p);
int32_t			flag5(t_pinfo *p);
int32_t			flag6(t_pinfo *p);

void			ft_test_print_lem(t_lem *lem);
void			ft_parsing(t_lem *lem, char *filename);
void			ft_add_link(t_lem *lem, char *line);
void			ft_adj_matrix_creater(t_lem *lem);
void			ft_src_valid_cheker(t_lem *lem);
int				ft_add_room(t_lem *lem, char *line, int index);
int				ft_add_start_end_room(t_lem *lem, char *p);
void			ft_list_of_rooms_creater(t_lem *lem);
void			ft_input_counter(t_lem *lem, char *p);
char			*ft_get_src(t_lem *lem, char *filename);
char			**ft_matrix(size_t size1, size_t size2, char c);
int				ft_strchr_index(const char *s, int c);
int				ft_strnchr_index(const char *s, unsigned char c, int len);
char			**ft_arrdel(char ***arr);
void			ft_cut_lists(t_lem *lem);
void			ft_matrix_correcter_finish(t_lem *lem);
void			ft_matrix_correcter_start(t_lem *lem);
void			ft_matrix_correcter(t_lem *lem);
void			ft_start_finish_counter(t_lem *lem);
void			ft_start_way_cut(t_lem *lem, int cur);
void			ft_start_ways_cut(t_lem *lem);
void			ft_var_parser(t_lem *lem, int32_t **res);
int				ft_way_comparison(t_lem *lem, int *next, int n_ways);
int				ft_get_final_sol(t_lem *lem, int n_sol, int **var);
void			ft_get_arr_ant(t_lem *lem);
int				ft_final_print(t_lem *lem);
int				ft_fill_cheker(t_lem *lem, int len);
char			*ft_skip_comment(char *str);
void			ft_free_all(t_lem *lem);
void			ft_free_sol(t_lem *lem, int n_sol);
void			ft_start_end_num_cheker(t_lem *lem);
void			ft_first_room_line_cheker(char *p);
void			ft_solution_creater(t_lem *lem);
int				ft_get_next_way(t_lem *lem, int **var, int n_sol, int x);
int				ft_get_next_solution(t_lem *lem, int **var, int n_sol, int x);
void			ft_way_comparison_creater(t_lem *lem);
int				ft_z_comparison_correcter(t_lem *lem, int prev_z);
int				ft_z_comparison(t_lem *lem, int next_z);
int				ft_way_comparison_correcter(t_lem *lem, int n_ways);
int				ft_way_comparison(t_lem *lem, int *next, int n_ways);
int32_t			sol_weight(t_solution p,
					int32_t **var, int32_t ants, int32_t elem);
int				ft_sol_creation(t_lem *lem, int32_t **var);
int				ft_src_print(t_lem *lem);
int				ft_print_ants_struct(t_lem *lem, int i);
int				ft_print_fin_ways(t_lem *lem, int i);
int				ft_print_status(t_lem *lem, int i);
void			ft_print(t_lem *lem);
/*
**		helpers.c
*/
void			print_tab(int32_t **tab, int32_t y, int32_t x);
int				**create_tab(int y, int x);
void			ft_test_print_lem(t_lem *lem);
void			ft_print_all_sol(t_lem *lem, int n_sol, int **var);
void			ft_print_sol(t_lem *lem, int n_sol, int **var);
void			ft_print_fin_sol_struct(t_lem *lem);
#endif
