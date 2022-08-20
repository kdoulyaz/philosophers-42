/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:01 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:35 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

void	ft_clear(t_main *status)
{
	int	i;

	i = -1;
	while (++i < status->nbr_philo)
		pthread_detach(status->philos[i].thread);
	free(status->philos);
	while (++i < status->nbr_philo)
		pthread_mutex_destroy(&status->forks[i]);
	free(status->forks);
}

int	create_philo(t_main *status)
{
	int	i;

	status->eat_count = 0;
	status->philos = malloc(sizeof(t_philo) * status->nbr_philo);
	status->forks = malloc(sizeof(pthread_mutex_t) * status->nbr_philo);
	pthread_mutex_init(&status->m_print, NULL);
	pthread_mutex_init(&status->m_protect, NULL);
	i = -1;
	while (++i < status->nbr_philo)
		pthread_mutex_init(&status->forks[i], NULL);
	pthread_mutex_init(&status->m_good, NULL);
	pthread_mutex_init(&status->m_eat_count, NULL);
	status->time = get_time();
	start_half(status, 0);
	ft_usleep(status, 10);
	start_half(status, 1);
	pthread_create(&status->monitor, NULL, checker, status);
	pthread_join(status->monitor, NULL);
	ft_clear(status);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (ac > 4 && ac <= 6)
	{
		if (!err_handling(ac, av, &main))
			return (1);
		main.good = 1;
		create_philo(&main);
		return (0);
	}
	write(2, "Invalide Number of args!\n", 25);
	return (1);
}
