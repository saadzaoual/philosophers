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