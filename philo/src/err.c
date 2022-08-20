/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:17:59 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/08/20 08:32:32 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/philo.h"

int	init_args(int ac, char **av, t_main *main)
{
	main->nbr_philo = ft_atoi(av[1]);
	main->time_to_die = ft_atoi(av[2]);
	main->time_to_eat = ft_atoi(av[3]);
	main->time_to_sleep = ft_atoi(av[4]);
	main->nbr_eat = -1;
	if (ac == 6)
		main->nbr_eat = ft_atoi(av[5]);
	return (0);
}

int	err_handling(int ac, char **av, t_main *main)
{
	init_args(ac, av, main);
	if (main->nbr_philo <= 0 || main->time_to_die <= 0
		|| main->time_to_eat <= 0 || main->time_to_sleep <= 0
		|| (ac == 6 && main->nbr_eat <= 0))
	{
		write(2, "Error IN args\n", 14);
		return (0);
	}
	return (1);
}
