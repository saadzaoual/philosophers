/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:04:01 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/31 10:04:01 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t get_time_in_ms(void)
{
    struct timeval      tv;

    gettimeofday(&tv,NULL);
    return((&tv.tv_sec * 1000) + (&tv.tv_usec / 1000));
}

void	philo_sleep(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up)
	{
		if (has_simulation_stopped(table))
			break ;
		usleep(100);
	}
}

void	sim_start_delay(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}