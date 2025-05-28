/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaoual <szaoual@students.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:27:17 by szaoual           #+#    #+#             */
/*   Updated: 2025/05/27 23:40:21 by szaoual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//free the table :);
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
		while (i < table->nb_philos)
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
// msg <3 : function bax treturn lerror msg (return int);
int	msg(char *str, char *detail, int exit_no)
{
	if (!detail)
		printf(str, STR_PROGRAM);
	else
		printf(str, STR_PROGRAM, detail);
	return (exit_no);
}
/*
    error_fail:
    1-free allocation of table;
    2-return 0;
*/
int	error_fail(char *str, char *details, t_table *table)
{
	if (table != NULL)
		free_table(table);
	return (msg(str, details, 0));
}
/*
    error_null:
	1-Frees any allocation of table;
    2-prints error message and returns a NULL pointer;
*/
void	*error_null(char *str, char *details, t_table *table)
{
	if (table != NULL)
		free_table(table);
	msg(str, details, 0);
	return (NULL);
}
