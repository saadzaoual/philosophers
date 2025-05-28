/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@students.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:43:24 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 23:52:35 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
/******************************************************************************
*                                 Headers                                     *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
/******************************************************************************
*                           printed_errors-msgs                               *
******************************************************************************/
# define STR_MAX_PHILOS "250"
# define STR_PROGRAM	"philo:"
# define STR_USAGE	"%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"
# define STR_INPUT_DIGIT	"%s invalid input: %s: \
not a valid unsigned integer between 0 and 2147483647.\n"
# define STR_INPUT_POFLOW	"%s invalid input: \
there must be between 1 and %s philosophers.\n"
# define STR_THREAD	"%s error: Could not create thread.\n"
# define STR_MALLOC	"%s error: Could not allocate memory.\n"
# define STR_MUTEX	"%s error: Could not create mutex.\n"
/******************************************************************************
*                                 Structs                                     *
******************************************************************************/
typedef struct s_philo	t_philo;
typedef struct s_table
{
	time_t			start_time;
	unsigned int	nb_philos;
	pthread_t		starv_checker;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat_count;
	int			sim_stop;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		times_ate;
	unsigned int		fork[2];
	pthread_mutex_t		meal_time_lock;
	time_t				last_meal;
	t_table				*table;
}	t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}	t_status;
/******************************************************************************
*                                Functions                                    *
******************************************************************************/
int     is_valid_input(int ac, char **av);
int	msg(char *str, char *detail, int exit_no);
int	error_fail(char *str, char *details, t_table *table);
void	*error_null(char *str, char *details, t_table *table);
#endif