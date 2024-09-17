/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_validate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:06:45 by asanni            #+#    #+#             */
/*   Updated: 2024/09/16 15:34:29 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid(char *str)
{
	long	nbr;

	if (!str)
		return (1);
	nbr = ft_atol(str);
	if (nbr == -2)
	{
		printf("Only numbers allowed\n");
		return (1);
	}
	if (nbr <= 0)
	{
		printf("Only positive numbers allowed!\n");
		return (1);
	}
	if (nbr > 2147483647)
	{
		printf("Max int is 2147483647\n");
		return (1);
	}
	return (0);
}

int	min__time_validation(char *arg)
{
	long	nbr;

	nbr = ft_atol(arg);
	if (nbr < 60)
	{
		printf("Min time to die should be 60ms!\n");
		return (1);
	}
	return (0);
}

int	max_philo_validation(char *arg)
{
	long	nbr;

	nbr = ft_atol(arg);
	if (nbr > 200)
	{
		printf("Max philos should be 200ms!\n");
		return (1);
	}
	return (0);
}

int	validate_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
		is_valid(args[i++]);
	min__time_validation(args[2]);
	max_philo_validation(args[1]);
	return (0);
}
