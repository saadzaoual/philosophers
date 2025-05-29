/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:19:41 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/28 14:19:41 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	start_simulation(t_table *table)
{
	unsigned int	i;

	table->start_time = get_time_in_ms() + (table->nb_philos * 2 * 10);
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&philosopher, table->philos[i]) != 0)
			return (error_failure(STR_ERR_THREAD, NULL, table));
		i++;
	}
	if (table->nb_philos > 1)
	{
		if (pthread_create(&table->grim_reaper, NULL,
				&grim_reaper, table) != 0)
			return (error_failure(STR_ERR_THREAD, NULL, table));
	}
	return (true);
}

static void	stop_simulation(t_table	*table)
{
	unsigned int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->nb_philos > 1)
		pthread_join(table->grim_reaper, NULL);
	if (DEBUG_FORMATTING == true && table->must_eat_count != -1)
		write_outcome(table);
	destroy_mutexes(table);
	free_table(table);
}

int main(int ac,char **av)
{
    t_table *table;
    
    if (ac - 1 < 4 || ac - 1 > 5)
		return (msg(STR_USAGE, NULL, 0));
	if (!is_valid_input(ac, av))
		return (0);
    table = init_table(ac, av, 1);
	if (!table)
	    return (0);
    if (!start_simulation(table))
		return (0);
    stop_simulation(table);
    return (1);
}