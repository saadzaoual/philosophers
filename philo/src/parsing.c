/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:49:48 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/29 14:49:48 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int  only_digits(char *str)
{
    int i;

    i = 0;

    while(str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int	my_atoi(char *str)
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
	if (nb > INT_MAX)
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
            printf("Error : the arguments should only contain digits!\n");
            return 0;
        }
        nb = my_atoi(av[i]);
        if(i == 1 && nb > MAX_PHILOS)
        {
            printf("Error : you exced the max number of philos %d!\n",MAX_PHILOS);
            return 0;
        }
        if (i != 1 && nb == -1)
        {
			printf("Error : not a valid unsigned integer between 0 and 2147483647.\n");
            return 0;
        }
        i++;
    }
    return 1;
}