/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:35:59 by aerdogan          #+#    #+#             */
/*   Updated: 2024/01/18 11:16:11 by aerdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long long		last_eat;
	pthread_mutex_t	lock;
	pthread_mutex_t	t_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				ph_cnt;
	int				eat_cnt;
	int				is_dead;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				was_eaten;
	t_philo			*philo;
	pthread_t		*tid;
	long long		start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	d_lock;
	pthread_mutex_t	we_lock;
	pthread_mutex_t	*forks;
}	t_data;

int			err(char *str);
int			is_dead(t_philo *philo);
int			ft_atoi(const char *str);
int			philo_create(t_data *data, int i);
int			load(t_data *data, int argc, char **argv);
int			dead_check(t_data *data, int i, int check);
void		my_sleep(t_data *data, int time);
void		msg(t_philo *philo, char *str);
long long	get_time(void);

#endif
