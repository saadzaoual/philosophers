/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 04:01:19 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 04:01:19 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 5

typedef struct s_args
{
    int id;
} t_args;

void *routine(void *arg)
{
    t_args *args = (t_args *)arg;
    int i = 0;

    while(i < 5)
    {
        printf("[threads %d] Count: %d.\n",args->id,i);
        usleep(1000000);
        i++;
    }
    return NULL;
}
int main(void)
{
    pthread_t threads[NUM_THREADS];
    t_args args[NUM_THREADS];
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
    
    return 0;
}