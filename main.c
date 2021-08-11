/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:30:20 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/10 10:26:22 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_zero(t_philo *ph)
{
	ph->num_of_philos = 0;
	ph->time_to_eat = 0;
	ph->time_to_sleep = 0;
	ph->time_to_die = 0;
	ph->num_ph_must_eat = 0;
	ph->launch_time = 0;
	ph->cnt_death = -1;//?
}

int	ft_mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_of_philos);
	while (i < philo->num_of_philos)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->print, NULL);
	return (0);
}

int		ft_philo_create(t_init *init, t_philo philo)
{
	int i;
	void	*init_ph;

	i = 0;
	philo.launch_time = ft_grinvich();
	while (i < philo.num_of_philos)
	{
		init[i].timer = ft_grinvich();
		init[i].index = i + 1;
		init[i].cnt_eat = 0;
		init[i].fork_l = i;
		init[i].fork_r = (i + 1) % philo.num_of_philos;
		init[i].philo = &philo;
		init_ph = (void *)&init[i];
		if (pthread_create(&init[i].threads, NULL, ft_philo_life, init_ph))
			return (-1);
		i++;
	}
	return (0);
}

int 	ft_stewart(t_init *init)
{
	int				i;
	unsigned long	diff_time1;
	unsigned long	diff_time2;
	while (1)
	{
		i = 0;
		while (i < init->philo->num_of_philos)
		{
			if (init->cnt_eat == init[i].philo->num_ph_must_eat)
			{
				pthread_mutex_lock(&init->philo->print);
				pthread_detach(init[i].threads);
				printf(YEL"Everyone has eaten, everyone is happy!\n");
				pthread_mutex_destroy(&(init->philo->forks[i++]));
				return (0);
			}
			i++;
			diff_time1 = ft_grinvich() - init[i].timer;
			if ((int)diff_time1 >= init->philo->time_to_die)
			{
				pthread_mutex_lock(&init->philo->print);
				diff_time2 = ft_grinvich() - init->philo->launch_time;
				pthread_detach(init[i].threads);
				printf(RED"%lu\t\t%d\t\tis died\n", diff_time2, init->index);
				pthread_mutex_destroy(&(init->philo->forks[i++]));
				return (0);
			}
			i++;
//			if (i == init->philo->num_of_philos)
//				i = 0;
		}
	}
}

int		main(int argc, char **argv)
{
	t_philo	philo;
	t_init	*init;

	ft_init_zero(&philo);
	if (argc == 5 || argc == 6)
	{
		ft_check_param(&philo, argc, argv);
		if (ft_check_input_num(&philo))
		{
			printf(RED"Error: write correct argument's!\n");
			return (0);
		}
		ft_mutex_init(&philo);
		init = malloc (sizeof(t_init) * philo.num_of_philos);
		if (!(init))
			return (-1);
		ft_philo_create(init, philo);
		ft_stewart(init);
		free(init->philo->forks);
	}
	else
		printf(RED"Error: argument's!\n");
	return (0);
}
