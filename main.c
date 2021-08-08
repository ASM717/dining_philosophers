/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:30:20 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/08 08:51:46 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	grinvich(void)
{
	struct timeval	time;
	unsigned long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_usleep(int ms)
{
	unsigned long	time;

	time = grinvich() + ms;
	while ((grinvich() < time))
		usleep(10);
}

void	ft_print_param(t_philo *ph, int argc)
{
	printf("NUM = %d\n", ph->num_of_philos);
	printf("DIE = %ld\n", ph->time_to_die);
	printf("EAT = %ld\n", ph->time_to_eat);
	printf("SLE = %ld\n", ph->time_to_sleep);
	if (argc == 6)
		printf("N_E = %d\n", ph->num_ph_must_eat);
}

void	ft_init_zero(t_philo *ph)
{
	ph->num_of_philos = 0;
	ph->time_to_eat = 0;
	ph->time_to_sleep = 0;
	ph->time_to_die = 0;
	ph->num_ph_must_eat = 0;
	ph->launch_time = 0;
	//ph->cnt = 0;
	ph->cnt_death = 0;
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

// int	ft_maximum_eat(t_init *init)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < init->philo->num_ph_must_eat)
// 	{
// 		if (init[i].cnt_eat < init->philo->num_ph_must_eat)
// 			return (0);
// 	}
// 	//finish = 1;
// 	return (1);
// }

void	*ft_philo_life(void *kinit)
{
	t_init	*init;
	//unsigned long	diff_time;

	init = (t_init *)kinit;
	//diff_time = grinvich() - init->philo->launch_time;
	if (init->index % 2)
		ft_usleep(init->philo->time_to_eat / 2); //уточнить
	while (1)
	{
		pthread_mutex_lock(&init->philo->forks[init->fork_l]);
		printf("%lu\t\t%d\t\thas taken a fork\n", grinvich() - init->philo->launch_time, init->index);
		pthread_mutex_lock(&init->philo->forks[init->fork_r]);
		printf("%lu\t\t%d\t\thas taken a fork\n", grinvich() - init->philo->launch_time, init->index);

		init->timer = grinvich();
		init->cnt_eat++;
		//eating
		printf("%lu\t\t%d\t\tis eating\n", grinvich() - init->philo->launch_time, init->index);
		ft_usleep(init->philo->time_to_eat);
		pthread_mutex_unlock(&init->philo->forks[init->fork_l]);
		pthread_mutex_unlock(&init->philo->forks[init->fork_r]);
		printf("%lu\t\t%d\t\tis sleeping\n", grinvich() - init->philo->launch_time, init->index);
		ft_usleep(init->philo->time_to_sleep);
		printf("%lu\t\t%d\t\tis thinking\n", grinvich() - init->philo->launch_time, init->index);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_init	*init;
	void	*init_ph;
	int		i;

	ft_init_zero(&philo);
	if (argc == 5 || argc == 6)
	{
		ft_check_param(&philo, argc, argv);
		if (ft_check_input_num(&philo))
		{
			printf("Error: write correct argument's!\n");
			return (0);
		}
		ft_mutex_init(&philo);
		philo.launch_time = grinvich();
		init = malloc (sizeof(t_init) * philo.num_of_philos);
		if (!(init))
			return (-1);
		i = 0;
		while (i < philo.num_of_philos)
		{
			init[i].timer = grinvich();
			init[i].index = i;
			init[i].cnt_eat = 0;
			init[i].fork_l = i;
			init[i].fork_r = (i + 1) % philo.num_of_philos;
			init[i].philo = &philo;
			init_ph = (void *)&init[i];
			if (pthread_create(&init[i].threads, NULL, ft_philo_life, init_ph))
				return (-1);
			i++;
		}
		//pthread_detach(init->threads);
		i = 0;
		while (i < philo.num_of_philos)
			pthread_join(init[i++].threads, NULL);
		i = 0;
		while (i < philo.num_of_philos)
			pthread_mutex_destroy(&(init->philo->forks[i++]));
		//ft_print_param(&philo, argc);
	}
	else
		printf("Error: argument's!\n");
	return (0);
}
