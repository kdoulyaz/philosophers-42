/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:25:01 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:44 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

long long	get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(t_main *status, int stop_ms)
{
	long long	end_ms;

	end_ms = get_time() + stop_ms;
	while (get_time() < end_ms)
	{
		pthread_mutex_lock(&status->m_good);
		if (status->good != 1)
		{
			pthread_mutex_unlock(&status->m_good);
			return ;
		}
		pthread_mutex_unlock(&status->m_good);
		usleep(100);
	}
}
