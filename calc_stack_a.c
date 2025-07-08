/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:02:48 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/08 19:52:50 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static void	max_number(t_stack *b, t_calc *calc)
{
	int	i;

	i = 0;
	calc->target = calc->number;
	while (i < b->size)
	{
		if (b->array[i] > calc->target)
		{
			calc->target = b->array[i];
			calc->target_pos = i;
		}
		i++;
	}
}

static void	closest_min(t_stack *b, t_calc *calc)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		if (b->array[i] < calc->number)
		{
			if (b->array[i] > calc->target)
			{
				calc->target = b->array[i];
				calc->target_pos = i;
			}
		}
		i++;
	}
	if (calc->target == -2147483649)
		max_number(b, calc);
}

static t_calc	*a_create_calc(t_stack *a, t_stack *b, int i)
{
	t_calc	*calc;

	calc = s_calc_creation(a->array[i], i);
	closest_min(b, calc);
	times_rotation(a, b, calc);
	return (calc);
}

t_calc	*calc_to_a(t_stack *a, t_stack *b)
{
	t_calc	*calc;
	int		i;
	int		cost_sum;
	int		total_cost;
	int		better_pos;

	i = 0;
	total_cost = 1000;
	while (i < a->size)
	{
		calc = a_create_calc(a, b, i);
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
	calc = a_create_calc(a, b, better_pos);
	return (calc);
}
