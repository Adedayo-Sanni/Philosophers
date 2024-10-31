/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:48:32 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:28:55 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dinner(t_dinner *dinner, char **argv, int argc)
{
	dinner->forks = NULL;
	dinner->philos = NULL;
	init_data(dinner, argv, argc);
	init_forks(dinner);
	init_philos(dinner);
	start_philos(dinner);
}

void	init_forks(t_dinner *dinner)
{
	int	i;

	if (!dinner)
		error_exit("Invalid data", DATA, dinner);
	dinner->forks = malloc(dinner->data.nb_philos * \
		sizeof(pthread_mutex_t));
	if (!dinner->forks)
	{
		error_exit("Sorry, were out of forks", FORK, dinner);
		return ;
	}
	i = 0;
	while (i < dinner->data.nb_philos)
	{
		if (pthread_mutex_init(&dinner->forks[i], NULL) != 0)
		{
			error_exit("Sorry, were out of forks", FORK, dinner);
			return ;
		}
		i++;
	}
}

void	init_data(t_dinner *dinner, char **argv, int argc)
{
	dinner->data.stop = 0;
	pthread_mutex_init(&dinner->data.message, NULL);
	pthread_mutex_init(&dinner->data.check, NULL);
	pthread_mutex_init(&dinner->data.time, NULL);
	dinner->data.nb_philos = ft_atol(argv[1]);
	dinner->data.time_to_die = ft_atol(argv[2]);
	dinner->data.time_to_eat = ft_atol(argv[3]);
	dinner->data.time_to_sleep = ft_atol(argv[4]);
	dinner->data.philo_died = 0;
	if (argc == 6)
		dinner->data.nb_meals_todo = ft_atol(argv[5]);
	else
		dinner->data.nb_meals_todo = -1;
}

void	init_philos(t_dinner *dinner)
{
	int	i;

	dinner->philos = malloc(dinner->data.nb_philos * sizeof(t_philo));
	if (!dinner->philos)
		error_exit("Where is the guests?", PHILO, dinner);
	pthread_mutex_init(&dinner->philos->update, NULL);
	pthread_mutex_init(&dinner->data.monitor, NULL);
	pthread_mutex_init(&dinner->philos->eat, NULL);
	i = 0;
	while (i < dinner->data.nb_philos)
	{
		dinner->philos[i].philo_id = i + 1;
		dinner->philos[i].left_fork = &dinner->forks[i];
		dinner->philos[i].right_fork = &dinner->forks[(i + 1)
			% dinner->data.nb_philos];
		dinner->philos[i].meals_had = 0;
		dinner->philos[i].time_last_meal = current_time();
		dinner->philos[i].data = &dinner->data;
		pthread_mutex_init(&dinner->philos[i].update, NULL);
		i++;
	}
}
