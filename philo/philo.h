/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:31:42 by marvin            #+#    #+#             */
/*   Updated: 2024/08/19 22:31:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//Structs

typedef struct s_mutex
{
	pthread_mutex_t		mutex;
	long int			state;
}t_mutex;

typedef struct s_data
{
	short int			nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals_todo;
}t_data;

typedef struct s_philo
{
	pthread_t	philo;
	t_mutex		left_fork;
	t_mutex		right_fork;
	int			philo_id;
	int			max_meal;
	int			meals_had;
}t_philo;

// contém todas as outras structs
typedef struct s_dinner
{
}t_dinner;

//Functions
long	ft_atol(const char *nptr);
int		validate_args(char **args);

#endif
