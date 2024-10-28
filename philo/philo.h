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

typedef struct s_data
{
	short int		nb_philos;
	long int		time_to_die;
	long long		start_time;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals_todo;
	int				philo_died;
	pthread_mutex_t	check;
	pthread_mutex_t	monitor;
	pthread_mutex_t	message;
	_Atomic int		stop;
}	t_data;

typedef struct s_philo
{
	pthread_t			self_thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		update;
	int					philo_id;
	int					max_meal;
	int					meals_had;
	long int			time_last_meal;
	t_data				*data;
}	t_philo;

// Estrutura que contém todas as outras structs
typedef struct s_dinner
{
	pthread_mutex_t	*forks;
	pthread_t		supervisor;
	t_philo			*philos;
	t_data			data;
}	t_dinner;

typedef enum e_type
{
	PHILO = 1,
	FORK,
	DATA,
}	t_type;

//Functions
long		ft_atol(const char *nptr);
int			validate_args(char **args);
void		init_dinner(t_dinner *dinner, char **argv, int argc);
void		init_data(t_dinner *dinner, char **argv, int argc);
void		init_philos(t_dinner *dinner);
void		init_forks(t_dinner *dinner);
void		cleanup(t_dinner *dinner);
void		error_exit(char *msg, int clean, t_dinner *dinner);
void		*philos_routines(void *philo_arg);
void		print_msg(long long time, t_philo *philo, char *msg);
long long	current_time(void);
int			is_alive(t_philo *philo);
int			is_satisfied(t_philo *philo);
void		take_fork(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_thinks(t_philo *philo);
void		release_fork(t_philo *philo);
void		start_philos(t_dinner *dinner);
int			is_dead(t_philo *philo);
void		free_forks(t_dinner *dinner);
void		clean_philos(t_dinner *dinner);
void		*supervisor_routine(void *arg);

#endif
