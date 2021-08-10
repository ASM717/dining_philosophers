/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:14:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/10 12:14:46 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_mutex_forks(t_init *init, unsigned long	diff_time)
{
	pthread_mutex_lock(&init->philo->forks[init->fork_l]);
	diff_time = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	printf(GREEN"%lu\t\t%d\t\thas taken a fork\n", diff_time, init->index);
	pthread_mutex_unlock(&init->philo->print);
	pthread_mutex_lock(&init->philo->forks[init->fork_r]);
	diff_time = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	printf(GREEN"%lu\t\t%d\t\thas taken a fork\n", diff_time, init->index);
	pthread_mutex_unlock(&init->philo->print);
}

static void	ft_mutex_brunch(t_init *init, unsigned long	diff_time)
{
	diff_time = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	printf(PURPLE"%lu\t\t%d\t\tis eating\n", diff_time, init->index);
	pthread_mutex_unlock(&init->philo->print);
	ft_myusleep(init->philo->time_to_eat);
	pthread_mutex_unlock(&init->philo->forks[init->fork_l]);
	pthread_mutex_unlock(&init->philo->forks[init->fork_r]);
}

static void	ft_mutex_relax(t_init *init, unsigned long	diff_time)
{
	diff_time = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	printf(SKY"%lu\t\t%d\t\tis sleeping\n", diff_time, init->index);
	pthread_mutex_unlock(&init->philo->print);
	ft_myusleep(init->philo->time_to_sleep);
	diff_time = ft_grinvich() - init->philo->launch_time;
	pthread_mutex_lock(&init->philo->print);
	printf(BLUE"%lu\t\t%d\t\tis thinking\n", diff_time, init->index);
	pthread_mutex_unlock(&init->philo->print);
}

void	*ft_philo_life(void *kinit)
{
	t_init			*init;
	unsigned long	diff_time;

	init = (t_init *)kinit;
	diff_time = 0;
	if (init->index % 2)
		ft_myusleep(init->philo->time_to_eat / 2);
	while (init->cnt_eat != init->philo->cnt_death)
	{
		ft_mutex_forks(init, diff_time);
		init->timer = ft_grinvich();
		init->cnt_eat++;
		ft_mutex_brunch(init, diff_time);
		ft_mutex_relax(init, diff_time);
	}
	return (NULL);
}
