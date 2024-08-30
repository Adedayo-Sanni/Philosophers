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

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/wait.h>

//Structs

typedef struct s_philo
{
}t_philo;

typedef struct s_dinner
{
}t_dinner;

//Functions
long	ft_atol(const char *nptr);
int		validate_args(char **args);

#endif
