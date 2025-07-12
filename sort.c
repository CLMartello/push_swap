/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:42:48 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 17:51:32 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	sort_three_numbers(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
		rotate(a);
	else if (a->array[1] > a->array[2] && a->array[1] > a->array[0])
		rev_rotate(a);
	if (a->array[0] > a->array[1])
		swap(a);
}

void	operation(t_stack *a, t_stack *b, t_calc *calc)
{
	while (calc->rr-- > 0)
		rr_print(a, b);
	while (calc->rrr-- > 0)
		rrr_print(a, b);
	while (calc->ra-- > 0)
		rotate(a);
	while (calc->rb-- > 0)
		rotate(b);
	while (calc->rra-- > 0)
		rev_rotate(a);
	while (calc->rrb-- > 0)
		rev_rotate(b);
	push(a, b);
}

int	final_move(t_stack *a, t_stack *b)
{
	t_calc	*calc;

	calc = malloc(sizeof(t_calc));
	if (!calc)
		return (0);
	calc = s_calc_creation(calc, a->array[0], 0);
	if (!calc)
		return (0);
	min_number(a, calc);
	calc->pos = calc->target_pos;
	if (a->array[0] != calc->target)
		times_rotation(a, b, calc);
	while (calc->ra-- > 0)
		rotate(a);
	while (calc->rra-- > 0)
		rev_rotate(a);
	free(calc);
	return (0);
}

void	move(t_stack *a, t_stack *b)
{
	t_calc	*calc;

	if (a->size > 3)
		push(a, b);
	if (a->size > 3)
		push(a, b);
	while (a->size > 3)
	{
		calc = calc_to_a(a, b);
		operation(a, b, calc);
		free(calc);
	}
	if (a->size == 3)
		sort_three_numbers(a);
	while (b->size > 0)
	{
		calc = calc_to_b(b, a);
		operation(b, a, calc);
		free(calc);
	}
	final_move(a, b);
}
