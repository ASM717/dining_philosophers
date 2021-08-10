/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <amuriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:30:48 by amuriel           #+#    #+#             */
/*   Updated: 2021/08/07 12:30:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_grinvich(void)
{
	struct timeval	time;
	unsigned long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_myusleep(int ms)
{
	unsigned long	time;

	time = ft_grinvich() + ms;
	while ((ft_grinvich() < time))
		usleep(500);
}

static int	ft_isspace(int c)
{
	while (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result > 2147483647 && sign == 1)
			return (-1);
		else if (result >= 2147483648 && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
