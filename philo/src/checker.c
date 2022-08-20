/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:39:12 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:29 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

int	check_eat(t_main *status)
{
	pthread_mutex_lock(&status->m_eat_count);
	if (status->eat_count >= status->nbr_philo * status->nbr_eat
		&& status->nbr_eat != -1)
	{
		pthread_mutex_lock(&status->m_good);
		status->good = 0;
		pthread_mutex_unlock(&status->m_good);
		pthread_mutex_unlock(&status->m_eat_count);
		return (1);
	}
	pthread_mutex_unlock(&status->m_eat_count);
	return (0);
}

int	check_life(t_main *status, int i)
{
	if (get_time() > status->philos[i].limit_eat)
	{
		pthread_mutex_lock(&status->m_print);
		pthread_mutex_lock(&status->m_good);
		status->good = 0;
		pthread_mutex_unlock(&status->m_good);
		printf("%s%-10lld %-3d %-30s%s\n", PINK, get_time() - status->time,
			i + 1, DIED, RESET);
		return (1);
	}
	return (0);
}

void	*checker(void *arg)
{
	t_main		*status;
	int			i;

	status = (t_main *)arg;
	while (1)
	{
		pthread_mutex_lock(&status->m_protect);
		i = -1;
		while (++i < status->nbr_philo)
		{
			pthread_mutex_lock(&status->philos[i].m_eating);
			if (check_life(status, i) || check_eat(status))
			{
				pthread_mutex_unlock(&status->philos[i].m_eating);
				return (NULL);
			}
			pthread_mutex_unlock(&status->philos[i].m_eating);
		}
		pthread_mutex_unlock(&status->m_protect);
		usleep(100);
	}
}
