/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:33:40 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/29 14:33:40 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PHILO_H
#define     PHILO_H
/******************************************************************************
*                                   Headers                                   *
******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
# include <sys/time.h>
#include <stdlib.h>
/******************************************************************************
*                                   Macros                                    *
******************************************************************************/
#define MAX_PHILOS 200
#define INT_MAX 2147483647
/******************************************************************************
*                                   Structs                                  *
******************************************************************************/

typedef struct s_philo	t_philo;

typedef struct s_table
{
    time_t          start_time;
    unsigned int    nb_of_philos;
    pthread_t       starving_checker;
    time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
    int             must_eat_count;
    int 			sim_stop;
    int             simulation_stop;
    pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
} t_table;

typedef struct s_philo
{
    pthread_t           thread;
    unsigned int        id;
    unsigned int        time_ate;
    unsigned int        forks[2];
    pthread_mutex_t     meal_time_lock;
    time_t              last_meal;
    t_table             *table;
} t_philo;

/******************************************************************************
*                               Functions Prots                               *
******************************************************************************/
// parsing.c
int     is_valid_input(int ac, char **av);
int	my_atoi(char *str);
//init.c
t_table *init_table(int ac, char **av, int i);
//time.c
time_t get_time_in_ms(void);
#endif