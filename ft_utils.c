#include "philo.h"

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
