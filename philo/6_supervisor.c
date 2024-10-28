/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_supervisor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:13 by asanni            #+#    #+#             */
/*   Updated: 2024/10/28 20:14:14 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)arg;
	while (1)
	{
		i = 0;
		while (i < dinner->data.nb_philos)
		{
			if (is_alive(&dinner->philos[i]) == 0)
			{
				pthread_mutex_lock(&dinner->data.monitor);
				dinner->data.stop = 1;
				pthread_mutex_unlock(&dinner->data.monitor);
				return (NULL);
			}
			i++;
		}
	}
}
