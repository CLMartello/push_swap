/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:33:30 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/09 21:08:28 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_calc	*calc;

	if (a->size > 3)
		push(a, b);
	if (a->size > 3)
		push(a, b);
	while (a->size > 3)
	{
		calc = calc_to_a(a, b);
		move(a, b, calc);
		free(calc);
	}
	if (a->size == 3)
		sort_three_numbers(a);
	while (b->size > 0)
	{
		calc = calc_to_b(b, a);
		move(b, a, calc);
		free(calc);
	}
	final_move(a, b);
}

int	main(int argc, char *argv[])
{
	char	**array;
	long	*i_array;
	int		size;
	t_stack	*a;
	t_stack	*b;

	
	array = parse(argc, argv);
	size = size_array(array);
	i_array = array_creation(array, size);
	error(i_array, size);
	a = initialize_stack('a', i_array, size);
	i_array = malloc(size * sizeof(long));
	if (!i_array)
		return (0);
	b = initialize_stack('b', i_array, 0);
	if (a->size > 2)
		push_swap(a, b);
	else
		swap(a);
	free(a->array);
	free(b->array);
	free(a);
	free(b);
	return (0);
}
