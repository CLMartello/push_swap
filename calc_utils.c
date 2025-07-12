/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:14:14 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 17:52:06 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

t_calc	*s_calc_creation(t_calc *calc, long nbr, int pos)
{
	calc->number = nbr;
	calc->pos = pos;
	calc->target = -2147483649;
	calc->target_pos = -1;
	calc->ra = 0;
	calc->rb = 0;
	calc->rr = 0;
	calc->rra = 0;
	calc->rrb = 0;
	calc->rrr = 0;
	return (calc);
}

void	times_rotation(t_stack *a, t_stack *b, t_calc *calc)
{
	if (calc->pos <= (a->size / 2))
		calc->ra = calc->pos;
	else if (calc->pos > (a->size / 2))
		calc->rra = a->size - calc->pos;
	if (calc->target_pos <= (b->size / 2))
		calc->rb = calc->target_pos;
	else if (calc->target_pos > (b->size / 2))
		calc->rrb = b->size - calc->target_pos;
	while (calc->ra > 0 && calc->rb > 0)
	{
		calc->rr++;
		calc->ra--;
		calc->rb--;
	}
	while (calc->rra > 0 && calc->rrb > 0)
	{
		calc->rrr++;
		calc->rra--;
		calc->rrb--;
	}
}
