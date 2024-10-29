/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:49 by asanni            #+#    #+#             */
/*   Updated: 2024/10/29 14:05:26 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->data.start_time = current_time();
	while (i < dinner->data.nb_philos)
	{
		if (pthread_create(&dinner->philos[i].self_thread, NULL,
				philos_routines, &dinner->philos[i]) != 0)
		{
			error_exit("The guests could not come", PHILO, dinner);
			return ;
		}
		i++;
	}
	if (pthread_create(&dinner->supervisor, NULL,
			supervisor_routine, dinner) != 0)
	{
		error_exit("The waiter could not come", PHILO, dinner);
		return ;
	}
	i = 0;
	pthread_join(dinner->supervisor, NULL);
	while (i < dinner->data.nb_philos)
	{
		if (pthread_join(dinner->philos[i].self_thread, NULL) != 0)
		{
			error_exit("The guests wont leave", PHILO, dinner);
			return ;
		}
		i++;
	}
}
