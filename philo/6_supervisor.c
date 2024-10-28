/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_supervisor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:13 by asanni            #+#    #+#             */
/*   Updated: 2024/10/28 16:30:44 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *arg)
{
	t_dinner	*dinner;
	int			i;

	i = 0;
	dinner = (t_dinner *)arg;
	while (1)
	{
		while (i < dinner->data.nb_philos)
		{
			if (is_alive(dinner->philos) == 0)
			{
				pthread_mutex_lock(&dinner->data.monitor);
				dinner->data.stop = 1;
				pthread_mutex_unlock(&dinner->data.monitor);
			}
			i++;
		}
		usleep(1000);
	}
}

//definir a rotina do filo então se ele estiver satisfeito 
//ou morto definir atomic para 1 e parar tudo
