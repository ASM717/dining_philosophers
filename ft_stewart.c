/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stewart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:11:25 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/12 11:11:44 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_philo_must_eat(t_init *init, int i)
{
	pthread_mutex_destroy(&(init->philo->forks[i++]));
	pthread_detach(init[i].threads);
	printf(YEL"Everyone has eaten, everyone is happy!\n");
}

static void	ft_philo_must_dead(t_init *init, int i)
{
	unsigned long	diff_time2;

	diff_time2 = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	pthread_mutex_destroy(&(init->philo->forks[i++]));
	pthread_detach(init[i].threads);
	printf(RED"%lu\t\t%d\t\tis died\n", diff_time2, init->index);
}

int	ft_stewart(t_init *init)
{
	int				i;
	unsigned long	diff_time1;

	while (1)
	{
		i = 0;
		while (i < init->philo->num_of_philos)
		{
			if (init->philo->num_ph_eat == init->philo->num_of_philos)
			{
				ft_philo_must_eat(init, i);
				return (0);
			}
			diff_time1 = ft_grinvich() - init[i].timer;
			if ((int)diff_time1 >= init->philo->time_to_die)
			{
				ft_philo_must_dead(init, i);
				return (0);
			}
			i++;
		}
	}
}
