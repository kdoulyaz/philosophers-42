/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:37:31 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:20 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

void	print_message1(t_philo *philo, char *color, char *str)
{
	pthread_mutex_lock(&philo->status->m_print);
	if (philo->status->good == 1)
	{
		printf("%s%-10lld %-3d %-30s%-1s%d%s\n", color,
			get_time() - philo->status->time,
			philo->id + 1, str, "#", philo->nbr_eat + 1, RESET);
	}
	pthread_mutex_unlock(&philo->status->m_print);
}

void	print_message(t_philo *philo, char *color, char *str)
{
	pthread_mutex_lock(&philo->status->m_print);
	if (philo->status->good == 1)
	{
		printf("%s%-10lld %-3d %-30s%s\n", color,
			get_time() - philo->status->time,
			philo->id + 1, str, RESET);
	}
	pthread_mutex_unlock(&philo->status->m_print);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, B_BLUE, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, B_BLUE, "has taken a fork");
	pthread_mutex_lock(&philo->m_eating);
	if (philo->status->nbr_eat == -1)
		print_message(philo, G_CYAN, "is eating");
	else
		print_message1(philo, G_CYAN, "is eating");
	philo->last_eat = get_time();
	philo->limit_eat = philo->last_eat + philo->status->time_to_die;
	pthread_mutex_unlock(&philo->m_eating);
	ft_usleep(philo->status, philo->status->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	if (philo->status->nbr_eat != -1)
	{
		pthread_mutex_lock(&philo->status->m_eat_count);
		philo->nbr_eat += 1;
		philo->status->eat_count += 1;
		pthread_mutex_unlock(&philo->status->m_eat_count);
	}
}
