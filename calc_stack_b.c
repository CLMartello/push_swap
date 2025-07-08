/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:23:50 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/08 19:57:19 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	min_number(t_stack *b, t_calc *calc)
{
	int	i;

	i = 0;
	calc->target = calc->number;
	while (i < b->size)
	{
		if (b->array[i] < calc->target)
		{
			calc->target = b->array[i];
			calc->target_pos = i;
		}
		i++;
	}
}

void	closest_max(t_stack *b, t_calc *calc)
{
	int	i;

	i = 0;
	calc->target = 2147483648;
	while (i < b->size)
	{
		if (b->array[i] > calc->number)
		{
			if (b->array[i] < calc->target)
			{
				calc->target = b->array[i];
				calc->target_pos = i;
			}
		}
		i++;
	}
	if (calc->target == 2147483648)
		min_number(b, calc);
}

static t_calc	*b_create_calc(t_stack *a, t_stack *b, int i)
{
	t_calc	*calc;

	calc = s_calc_creation(a->array[i], i);
	closest_max(b, calc);
	times_rotation(a, b, calc);
	return (calc);
}

t_calc	*calc_to_b(t_stack *a, t_stack *b)
{
	t_calc	*calc;
	int		i;
	int		better_pos;
	int		cost_sum;
	int		total_cost;

	i = 0;
	total_cost = 1000;
	while (i < a->size)
	{
		calc = b_create_calc(a, b, i);
		cost_sum = calc->ra + calc->rb + calc->rr;
		cost_sum += calc->rra + calc->rrb + calc->rrr;
		if (cost_sum < total_cost)
		{
			total_cost = cost_sum;
			better_pos = calc->pos;
		}
		i++;
		free(calc);
	}
	calc = b_create_calc(a, b, better_pos);
	return (calc);
}
