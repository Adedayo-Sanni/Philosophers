/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:14:46 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:40:19 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr == NULL)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		return (-2);
	return (sign * result);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->message);
	if (is_dead(philo) != 1)
	{
		pthread_mutex_lock(&philo->data->time);
		printf("%lld %d %s\n", current_time() - philo->data->start_time,
			philo->philo_id, msg);
		pthread_mutex_unlock(&philo->data->time);
	}
	pthread_mutex_unlock(&philo->data->message);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->update);
	philo->time_last_meal = current_time();
	pthread_mutex_unlock(&philo->update);
}
