/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@students.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:55:16 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/04 12:03:11 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	contains_only_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int my_atoi(char *str)
{
	unsigned long long nb = 0;
	int i = 0;

	if (!str[0])
		return (-1);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);

		nb = nb * 10 + (str[i] - '0');

		if (nb > (unsigned long long)INT_MAX)
			return (-1);

		i++;
	}
	return ((int)nb);
}

int	is_valid_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i < ac)
	{
		if (!contains_only_digits(av[i]))
			return (msg(STR_ERR_INPUT_DIGIT, av[i], 0));
		nb = my_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > MAX_PHILOS))
			return (msg(STR_ERR_INPUT_POFLOW, STR_MAX_PHILOS, 0));
		if (i != 1 && nb == -1)
			return (msg(STR_ERR_INPUT_DIGIT, av[i], 0));
		i++;
	}
	return (1);
}
