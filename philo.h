/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:30:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/09 18:43:18 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define PURPLE		"\x1b[35m"
# define SKY		"\x1b[36m"

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_ph_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	unsigned long	launch_time;

	struct timeval	finish_eat_t2;
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
	int				dead_flag;
}t_init;

int	ft_atoi(const char *str);
int	ft_check_param(t_philo *philo, int argc, char **argv);
int	ft_check_input_num(t_philo *philo);

#endif
