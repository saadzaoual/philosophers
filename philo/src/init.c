/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:22:07 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/29 15:22:07 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*free_table(t_table *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->fork_locks != NULL)
		free(table->fork_locks);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->nb_of_philos)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}

static pthread_mutex_t *init_forks(t_table *table)
{
	pthread_mutex_t *forks;
	unsigned int i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_of_philos);
	if (!forks)
	{
		free_table(table);
		printf("error: Could not allocate memory for forks.\n");
		return NULL;
	}

	i = 0;
	while (i < table->nb_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&forks[--i]);
			free(forks);
			free_table(table);
			printf("error: Could not create mutex.\n");
			return NULL;
		}
		i++;
	}
	return forks;
}

static void	assign_forks(t_philo *philo)
{
	philo->forks[0] = philo->id;
	philo->forks[1] = (philo->id + 1) % philo->table->nb_of_philos;
	if (philo->id % 2)
	{
		philo->forks[0] = (philo->id + 1) % philo->table->nb_of_philos;
		philo->forks[1] = philo->id;
	}
}

static int  init_global_mutexes(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (0);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
    {
	    free_table(table);
        printf("error: Could not create mutex.\n");
        return 0;
    }
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
    {
		free_table(table);
        printf("error: Could not create mutex.\n");
        return 0;
    }
	return (1);
}
static t_philo  **init_philos(t_table *table)
{
    t_philo **philos;
    unsigned int i;

    philos = malloc(sizeof(t_philo) * table->nb_of_philos);
    if(!philos)
    {
        free_table(table);
        printf("error: Could not allocate memory for philos.\n");
        return 0;
    }
    i = 0;
    while(i < table->nb_of_philos)
    {
        philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
		{
            free_table(table);
            printf("error: Could not allocate memory for philos.\n");
            return 0;
        }
        if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
        {
            free_table(table);
            printf("error: Could not create mutex.\n");
            return 0;
        }
        philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->time_ate = 0;
		assign_forks(philos[i]);
		i++;
    }
    return philos;
}
t_table *init_table(int ac, char **av, int i)
{
    t_table *table;

    table = malloc(sizeof(t_table) * 1);
    if(!table)
    {
        free_table(table);
        printf("Error: cant load the table!\n");
        return 0;
    }
    table->nb_of_philos = my_atoi(av[i++]);
	table->time_to_die = my_atoi(av[i++]);
	table->time_to_eat = my_atoi(av[i++]);
	table->time_to_sleep = my_atoi(av[i++]);
	table->must_eat_count = -1;
    if (ac - 1 == 5)
		table->must_eat_count = my_atoi(av[i]);
    table->philos = init_philos(table);
	if (!table->philos)
		return (NULL);
    if (!init_global_mutexes(table))
		return (NULL);
	table->sim_stop = 0;
	return (table);
}