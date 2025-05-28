/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 05:20:41 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 05:20:41 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 5
#define ITERATIONS 10

pthread_mutex_t mutex;
int counter = 0;

typedef struct s_args
{
    int id;
}   t_args;

void    *routine(void *arg)
{
    t_args *args = (t_args *) arg;
    int i = 1;
    while(i <= ITERATIONS)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("[thread number :%d] Count = %d.\n",args->id,i);
        usleep(100000);
        pthread_mutex_unlock(&mutex);
        i++;
    }
    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];
    t_args args[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    int i = 0;
    while(i < NUM_THREADS)
    {
        args[i].id = i + 1;
        pthread_create(&threads[i],NULL,routine,&args[i]);
        i++;
    }
    i = 0;
    while(i < NUM_THREADS)
    {
        pthread_join(threads[i],NULL);
        i++;
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}