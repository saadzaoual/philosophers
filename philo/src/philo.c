/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:33:01 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/29 14:33:01 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
    if(ac - 1 < 4 || ac - 1 > 5)
    {
        printf("Args error: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
        return (0);
    }
    if(!is_valid_input(ac,av))
        return 0;
    table = init_table(ac,av,1);
    if(!table)
    {
        printf("Error : cant load the TABLE!\n");
        return 0;
    }
    printf("THIS SHIT IS WORKING!\n");
    return(0);
}