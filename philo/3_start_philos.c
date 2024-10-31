/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:49 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:34:47 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_dinner *dinner)
{
	int	i;

	i = 0;
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
}

void	start_philos(t_dinner *dinner)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&dinner->data.time);
	dinner->data.start_time = current_time();
	pthread_mutex_unlock(&dinner->data.time);
	create_thread(dinner);
	pthread_mutex_lock(&dinner->data.time);
	dinner->data.start_time = current_time();
	pthread_mutex_unlock(&dinner->data.time);
	supervisor_routine(dinner);
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
