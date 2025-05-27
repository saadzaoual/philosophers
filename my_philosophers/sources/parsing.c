/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:18:59 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/26 01:18:59 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int     only_digits(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int	integer_atoi(char *str)
{
	unsigned long long int	nb;
	int						i;

	i = 0;
	nb = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > 2147483647)
		return (-1);
	return ((int)nb);
}

int     is_valid_input(int ac, char **av)
{
    int i;
    int nb;

    i = 1;

    while(i < ac)
    {
        if(!only_digits(av[i]))
        {
            printf("invalid input: only digits as arguments.\n");
            return(0);
        }
        nb = integer_atoi(av[i]);
        if(i == 1 && (nb <= 0 || nb > 200))
        {
            printf("invalid input: TOO MUCH PHILOS.\n");
            return(0);
        }
        if(i == 2 && nb <= 0)
        {
            printf("the time_to_die must be over 0");
            i++;
        }
        if (i != 1 && nb == -1)
        {
            printf("invalid input: not a valid unsigned integer between 0 and 2147483647.\n");
			return (0);
        }
        i++;
    }
    return 1;
}