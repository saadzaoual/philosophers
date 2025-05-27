/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialazation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@students.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:22:11 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 23:52:18 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_table *init_table(int ac, char *av,int i)
{
    t_table *table;
    
    table = malloc(sizeof(t_table) * 1);
    if(!table)
        return (error_null(STR_MALLOC, NULL, 0));
    table->nb_philos = integer_atoi(av[i++]);
    table->time_to_die = integer_atoi(av[i++]);
    table->time_to_eat = integer_atoi(av[i++]);
    table->time_to_sleep = integer_atoi(av[i++]);
    table->must_eat_count = -1;
	if (ac - 1 == 5)
		table->must_eat_count = integer_atoi(av[i]);
    table->philos = init_philosophers(table);
    if (!table->philos)
		return (NULL);
    if (!init_global_mutexes(table))
		return (NULL);
	table->sim_stop = 0;
	return (table);
}