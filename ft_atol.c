/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:38:41 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/01 20:29:00 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

long	ft_atol(const char *nbr)
{
	int		i;
	long	value;
	long	signal;

	i = 0;
	value = 0;
	signal = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			signal *= -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		value = value * 10 + (nbr[i] - '0');
		i++;
	}
	return (value * signal);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		printf("Invalid number of arguments.");
	printf("My atoi: %ld\n", ft_atol(argv[1]));
//	printf("Original atoi: %d\n", atoi(argv[1]));
	return (0);
}*/
