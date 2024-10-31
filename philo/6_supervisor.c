/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_supervisor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:13 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:52:46 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*supervisor_routine(void *arg)
// {
// 	t_dinner	*dinner;
// 	int			i;

// 	dinner = (t_dinner *)arg;
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < dinner->data.nb_philos)
// 		{
// 			if (is_alive(&dinner->philos[i]) == 0)
// 			{
// 				pthread_mutex_lock(&dinner->data.monitor);
// 				dinner->data.stop = 1;
// 				pthread_mutex_unlock(&dinner->data.monitor);
// 				return (NULL);
// 			}
// 			i++;
// 			usleep(100);
// 		}
// 	}
// }

// int	is_alive(t_philo *philo)
// {
// 	long int	diff;

// 	pthread_mutex_lock(&philo->update);
// 	diff = current_time() - philo->time_last_meal;
// 	pthread_mutex_unlock(&philo->update);
// 	if (diff >= philo->data->time_to_die)
// 	{
// 		print_msg(philo, "died");
// 		philo->data->philo_died = 1;
// 		return (0);
// 	}
// 	return (1);
// }

// int	is_satisfied(t_philo *philo)
// {
// 	if (philo->meals_had == philo->data->nb_meals_todo)
// 		return (0);
// 	return (1);
// }

// int	is_dead(t_philo *philo)
// {
// 	int	verif;

// 	pthread_mutex_lock(&philo->data->check);
// 	verif = philo->data->stop;
// 	pthread_mutex_unlock(&philo->data->check);
// 	return (verif);
// }

int	everyone_ate(t_philo *philo)
{
	int	i;

	i = philo->data->nb_philos;
	while (i != 0)
	{
		i--;
		pthread_mutex_lock(&philo[i].eat);
		if (philo[i].meals_had != philo->data->nb_meals_todo)
		{
			pthread_mutex_unlock(&philo[i].eat);
			return (FALSE);
		}
		pthread_mutex_unlock(&philo[i].eat);
	}
	return (TRUE);
}

void	supervisor_routine(void *arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)arg;
	while (1)
	{
		i = 0;
		while (i < dinner->data.nb_philos)
		{
			if (is_alive(&dinner->philos[i]) == 0
				|| everyone_ate(&dinner->philos[0]) == TRUE)
			{
				pthread_mutex_lock(&dinner->data.monitor);
				dinner->data.stop = 1;
				pthread_mutex_unlock(&dinner->data.monitor);
				return ;
			}
			i++;
			usleep(150);
		}
	}
}

int	is_alive(t_philo *philo)
{
	long int	diff;

	pthread_mutex_lock(&philo->update);
	diff = current_time() - philo->time_last_meal;
	pthread_mutex_unlock(&philo->update);
	if (diff > philo->data->time_to_die)
	{
		print_msg(philo, "died");
		pthread_mutex_lock(&philo->data->check);
		philo->data->philo_died = 1;
		pthread_mutex_unlock(&philo->data->check);
		return (0);
	}
	return (1);
}

int	is_satisfied(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	if (philo->meals_had == philo->data->nb_meals_todo)
	{
		pthread_mutex_unlock(&philo->eat);
		return (0);
	}
	pthread_mutex_unlock(&philo->eat);
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	verif;

	pthread_mutex_lock(&philo->data->check);
	verif = philo->data->stop;
	pthread_mutex_unlock(&philo->data->check);
	return (verif);
}

// int	everyone_ate(t_dinner *dinner)
// {
// 	int	i;

// 	i = dinner->philos->data->nb_philos;
// 	while (i != 0)
// 	{
// 		i--;
// 		if (dinner->philos[i].meals_had != dinner->philos->data->nb_meals_todo)
// 			return (FALSE);
// 	}
// 	return (TRUE);
// }

// void	*supervisor_routine(void *arg)
// {
// 	t_dinner	*dinner;
// 	int			i;

// 	dinner = (t_dinner *)arg;
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < dinner->data.nb_philos)
// 		{
// 			if (is_alive(&dinner->philos[i]) == 0)
// 			{
// 				pthread_mutex_lock(&dinner->data.monitor);
// 				dinner->data.stop = 1;
// 				pthread_mutex_unlock(&dinner->data.monitor);
// 				return (NULL);
// 			}
// 			if (everyone_ate(dinner) == TRUE)
// 			{
// 				pthread_mutex_lock(&dinner->data.monitor);
// 				dinner->data.stop = 1;
// 				pthread_mutex_unlock(&dinner->data.monitor);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 	}
// }
