/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:30:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/08 08:39:10 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_ph_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	unsigned long	launch_time;
	//int				cnt;
	int				cnt_death;
}t_philo;

typedef struct s_init
{
	t_philo			*philo;
	int				index;
	int				cnt_eat;
	unsigned long	timer;
	int				fork_l;
	int				fork_r;
	pthread_t		threads;
}t_init;

int	ft_atoi(const char *str);
int	ft_check_param(t_philo *philo, int argc, char **argv);
int	ft_check_input_num(t_philo *philo);

#endif
