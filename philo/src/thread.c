/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:29:21 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:41 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->status->nbr_eat != -1
			&& philo->nbr_eat == philo->status->nbr_eat)
			return (NULL);
		if (check_good(philo->status))
			return (NULL);
		philo_eat(philo);
		if (check_good(philo->status))
			return (NULL);
		print_message(philo, BLUE, "is sleeping");
		ft_usleep(philo->status, philo->status->time_to_sleep);
		if (check_good(philo->status))
			return (NULL);
		print_message(philo, G_CYAN, "is thinking");
	}
}

void	find_forks(t_main *status, int id)
{
	status->philos[id].l_fork = &status->forks[id];
	if (id + 1 >= status->nbr_philo)
		status->philos[id].r_fork = &status->forks[0];
	else
		status->philos[id].r_fork = &status->forks[id + 1];
}

void	start_half(t_main *status, int i)
{
	while (i < status->nbr_philo)
	{
		status->philos[i].status = status;
		status->philos[i].id = i;
		status->philos[i].last_eat = status->time;
		status->philos[i].limit_eat = status->time + status->time_to_die;
		status->philos[i].nbr_eat = 0;
		find_forks(status, i);
		pthread_mutex_init(&status->philos[i].m_eating, NULL);
		pthread_create(&status->philos[i].thread, NULL, philosopher,
			&status->philos[i]);
		i += 2;
	}
}
