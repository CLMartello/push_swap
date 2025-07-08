/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:42:48 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/08 18:56:42 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	sort_three_numbers(t_stack *a)
{
	if (a->array[0] < a->array[1] && a->array[1] > a->array[2])
	{
		rev_rotate(a);
		if (a->array[0] > a->array[1])
			swap(a);
	}
	else if (a->array[0] > a->array[1] && a->array[0] < a->array[2])
		swap(a);
	else if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
	{
		rotate(a);
		if (a->array[0] > a->array[1])
			swap(a);
	}
	else
		rev_rotate(a);
}

void	move(t_stack *a, t_stack *b, t_calc *calc)
{
	while (calc->rr-- > 0)
		rr(a, b);
	while (calc->rrr-- > 0)
		rrr(a, b);
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

	calc = s_calc_creation(a->array[0], 0);
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
