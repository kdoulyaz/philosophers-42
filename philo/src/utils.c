/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:34 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:46 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + str[i] - '0';
		i++;
	}
	if (res < 0 || res > MAX_INT)
		return (-1);
	return (res);
}

int	check_good(t_main *status)
{
	pthread_mutex_lock(&status->m_good);
	if (!status->good)
	{
		pthread_mutex_unlock(&status->m_good);
		return (1);
	}
	pthread_mutex_unlock(&status->m_good);
	return (0);
}
