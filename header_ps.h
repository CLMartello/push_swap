/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:11:36 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/08 19:50:52 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PS_H

# define HEADER_PS_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	char	name;
	long	*array;
	int		size;
}		t_stack;

typedef struct s_calc
{
	long	number;
	int		pos;
	long	target;
	int		target_pos;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}		t_calc;

void	push_swap(t_stack *a, t_stack *b);

void	swap(t_stack *a);
void	sa(t_stack *a);
void	ss(t_stack *a, t_stack *b);

void	push(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);

void	rotate(t_stack *a);
void	ra(t_stack *a);
void	rr(t_stack *a, t_stack *b);

void	rev_rotate(t_stack *a);
void	rra(t_stack *a);
void	rrr(t_stack *a, t_stack *b);

int		size_array(char **array);
long	*array_creation(char **array, int size);
char	**parse(int argc, char **argv);
t_stack	*initialize_stack(char name, long *array, int size);

void	error(long *a, int size);
void	duplicate(long *a, int size);
void	only_digit(char **a, int size);
int		confirm_sort(long *a, int size);

char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	**ft_free_mem(char **result, int i);
long	ft_atol(const char *nbr);
int		ft_putstr(char *s);

t_calc	*s_calc_creation(long nbr, int pos);
void	times_rotation(t_stack *a, t_stack *b, t_calc *calc);
void	min_number(t_stack *b, t_calc *calc);
t_calc	*calc_to_a(t_stack *a, t_stack *b);
t_calc	*calc_to_b(t_stack *a, t_stack *b);

void	sort_three_numbers(t_stack *a);
void	move(t_stack *a, t_stack *b, t_calc *calc);
int		final_move(t_stack *a, t_stack *b);

#endif
