/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedayo <adedayo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:48:32 by asanni            #+#    #+#             */
/*   Updated: 2024/09/19 20:15:23 by adedayo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dinner(t_dinner *dinner, char **argv, int argc)
{
	dinner->data = calloc(1, sizeof(t_data));
	if (!dinner->data)
		error_exit("Erro ao alocar memória", 1, DATA, dinner);
	start_data(dinner, argv, argc);
}

void	start_data(t_dinner *dinner, char **argv, int argc)
{
	dinner->data->nb_philos = ft_atol(argv[1]);
	dinner->data->time_to_die = ft_atol(argv[2]);
	dinner->data->time_to_eat = ft_atol(argv[3]);
	dinner->data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		dinner->data->nb_meals_todo = ft_atol(argv[5]);
}

void	init_philos(t_dinner *dinner)
{
	int i;

	i = 0;
	while (i < dinner->data->nb_philos)
	{
		dinner->philos[i].philo_id = i + 1;
		dinner->philos[i].left_fork = &dinner->forks[i];
		dinner->philos[i].right_fork = &dinner->forks[(i + 1) % dinner->data->nb_philos];
		dinner->philos[i].meals_had = 0;
		dinner->philos[i].time_last_meal = 0;
		dinner->philos[i].data = dinner->data;
		i++;
	}
}

void init_forks(t_dinner *dinner, int i)
{
    if (i >= dinner->data->nb_philos)
        return;
    pthread_mutex_init(&dinner->forks[i].mutex, NULL);
    init_forks(dinner, i + 1);
}
