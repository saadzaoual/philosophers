/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@students.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:42:53 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 23:47:59 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
	t_table *table;
	
    if (ac != 5 && ac != 6)
		return (msg(STR_USAGE, NULL, 1));
	if(!is_valid_input(ac,av))
		return 1;
	table = init_table(ac,av,1);
    return (0);
}