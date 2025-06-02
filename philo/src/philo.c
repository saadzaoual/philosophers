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

static int start_simulation(t_table *table)
{
    unsigned int i;
    
    table->start_time = get_time_in_ms() + (table->nb_of_philos * 2 * 10);
    i = 0;
    while(i < table->nb_of_philos)
    {
        if(pthread_create(&table->philos[i]->thread, NULL,&philosopher, table->philos[i]) != 0)
        {
            free_table(table);
            printf("Error: creating the philosophers!\n");
            return 0;
        }
        i++;
    }
    if(table->nb_of_philos > 1)
    {
        if(pthread_create(&table->starving_checker, NULL,&starving_checker,table) != 0)
        {
            free_table(table);
            printf("Error: creating the starving_checker!\n");
            return 0;
        }
    }
    return 1;
}

int main(int ac, char **av)
{
    t_table *table;

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
    if(!start_simulation(table))
    {
        printf("Error : a simulation error!\n");
        return 0;
    }
    printf("THIS SHIT IS WORKING!\n");
    return(0);
}