/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuhler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:38:08 by nbuhler           #+#    #+#             */
/*   Updated: 2017/01/07 14:11:43 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct	s_array
{
	int		nb;
	char	direction;
}				t_array;

typedef struct	s_position
{
	int		line;
	int		column;
}				t_position;

typedef struct	s_function
{
	char	**(*f)(char **square, int n, t_position x, char c);
	int		id;
}				t_function;

int				ft_testchar(char *str);
int				ft_check_dot(char *str, int nbpart);
int				ft_check_slash(char *str, int nbpart);
int				ft_check_backsn(char *str, int nbpart);
int				ft_check_last_char(char *str);
int				ft_nbchar(char *str);
int				ft_nbpart(char *str);
int				ft_bsntest(char *str);
char			*bsnstr(char *str);
int				ft_check26(int *str);
int				ft_map_is_null(char *str);
char			*ft_alfa_order(char *str);
int				*ft_change_doble(int *str, int len);
int				ft_char_to_int(char c);
int				*ft_change_to_int(char *str);
int				*ft_part_id(char *str, int nbpart);
int				ft_fill_part1(char *str, int j, int i);
int				ft_fill_part2(char *str, int j, int i);
int				ft_fill_part3(char *str, int j, int i);
char			*ft_strnew(size_t size);
char			*ft_realloc(char *str, size_t length);
char			*ft_fill_str(int fd);
int				*ft_final_tab_int(int *tab, int len);
int				ft_error(char *str, int nbpart);
int				ft_size(int nb);
int				ft_square_score(char **square, int size);
int				ft_score(int *permutation, int *pieces, int alpha, \
				int sq_score);
char			fill_bsnstr(char *str, int i);
int				*ft_alfa_order_int(int *str, size_t len);
char			**new_square(int n);
int				*ft_tab_cpy(int *od_tab);
int				*ascending_order(int *old_tab);
char			**find_square(int *pieces, int size, t_list **permutations, \
				int *sc);
char			**try_this_size(int *pieces, t_list *permutation, int *size);
void			print_square(char **square, int n);
t_function		*init_put_t_tab(int size, int *pieces);
char			**squarecpy(char **src, int n);
char			**squarecmp(char **new_square, char **old_square, \
				int size);
t_list			*sjt_algo(int *tab);
char			**try_this_order(int size, int *pieces, int *ref, int alpha);
int				is_mobile_int(t_array *array, int size, int i);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			*init_solutions(t_array *array, int size);
void			*add_solution(t_list **solutions, t_array *array, int size);
char			**put_t0(char **square, int n, t_position x, char c);
char			**put_t1(char **square, int n, t_position x, char c);
char			**put_t2(char **square, int n, t_position x, char c);
char			**put_t3(char **square, int n, t_position x, char c);
char			**put_t4(char **square, int n, t_position x, char c);
char			**put_t5(char **square, int n, t_position x, char c);
char			**put_t6(char **square, int n, t_position x, char c);
char			**put_t7(char **square, int n, t_position x, char c);
char			**put_t8(char **square, int n, t_position x, char c);
char			**put_t9(char **square, int n, t_position x, char c);
char			**put_t10(char **square, int n, t_position x, char c);
char			**put_t11(char **square, int n, t_position x, char c);
char			**put_t12(char **square, int n, t_position x, char c);
char			**put_t13(char **square, int n, t_position x, char c);
char			**put_t14(char **square, int n, t_position x, char c);
char			**put_t15(char **square, int n, t_position x, char c);
char			**put_t16(char **square, int n, t_position x, char c);
char			**put_t17(char **square, int n, t_position x, char c);
char			**put_t18(char **square, int n, t_position x, char c);

#endif
