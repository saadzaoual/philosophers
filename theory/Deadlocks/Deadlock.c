/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:02:14 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 09:02:14 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1, mutex2;

void *thread1_routine(void *arg)
{
    pthread_mutex_lock(&mutex1);
    printf("Thread 1 locked mutex1.\n");
    usleep(100000); // Simulate delay

    pthread_mutex_lock(&mutex2);  // Waits indefinitely if thread2 already locked mutex2
    printf("Thread 1 locked mutex2.\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void *thread2_routine(void *arg)
{
    pthread_mutex_lock(&mutex2);
    printf("Thread 2 locked mutex2.\n");
    usleep(100000); // Simulate delay

    pthread_mutex_lock(&mutex1);  // Waits indefinitely if thread1 already locked mutex1
    printf("Thread 2 locked mutex1.\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_create(&thread1, NULL, thread1_routine, NULL);
    pthread_create(&thread2, NULL, thread2_routine, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
