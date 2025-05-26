/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:42:53 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/26 01:31:58 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
    if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo nb_philo time_to_die time_to_eat time_to_sleep [must_eat]\n");
		return (1);
	}
	if(!is_valid_input(ac,av))
		return 1;
    return (0);
}