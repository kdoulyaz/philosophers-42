/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:13:20 by kdoulyaz          #+#    #+#             */
/*   Updated: 2022/06/29 03:13:22 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<sys/time.h>
# include<pthread.h>
# include<stdatomic.h>
# define MAX_INT 2147483647

# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"
# define DIED "died ☠️"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_eat;
	long long		limit_eat;
	int				nbr_eat;
	pthread_mutex_t	m_eating;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_main	*status;
}	t_philo;

typedef struct s_main
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
	int				good;
	atomic_int		eat_count;
	pthread_mutex_t	m_eat_count;
	pthread_mutex_t	m_good;
	pthread_mutex_t	m_protect;
	long long		time;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
}	t_main;

typedef struct s_args
{
	t_main	*status;
	t_philo	*philo;
}	t_args;

int			err_handling(int argc, char **argv, t_main *main);
long long	ft_atoi(char *str);
long long	get_time(void);
void		ft_usleep(t_main *status, int stop_ms);
void		start_half(t_main *status, int i);
void		*checker(void *arg);
void		philo_eat(t_philo *philo);
int			check_good(t_main *status);
void		print_message(t_philo *philo, char *color, char *str);

#endif