/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:09:35 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:27:42 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# define COL_RED "\033[0;91m"
# define COL_GREEN "\033[0;92m"
# define COL_YELLOW "\033[0;93m"
# define COL_BLUE "\033[0;94m"
# define COL_MAGENTA "\033[0;95m"
# define END_COL "\033[0m"

typedef struct s_data {
	int				nbr;
	size_t			start;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				nbr2eat;
	bool			death;
	pthread_mutex_t	print;
	pthread_mutex_t	checking;
	int				ends;
	int				x;
	pthread_mutex_t	m_ends;
}	t_data;

typedef struct s_fork {
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo {
	int				id;
	t_data			*data;
	t_fork			*left;
	t_fork			*right;
	size_t			last_meal;
	size_t			start;
	int				eat;
	int				end;
	pthread_mutex_t	stime;
}	t_philo;

int		ft_atoi(char *str);
size_t	ft_time(void);
size_t	ft_time_passed(size_t start);
int		ft_sleep(size_t time, t_data *dt);
void	*_routine(void *arg);
bool	_ckeckphilo_end(t_philo *ph);
void	one_handler(t_data *data);
bool	print_status(t_philo *philo, char c);
bool	is_death(t_data *data);
bool	check_end(t_data *data);
void	set_end(t_philo *philo);
void	set_death(t_data *data);
bool	is_end_simulation(t_philo *ph, int *i, int *eatnbr);
int		_validate_args(int ac, char **av, t_data *dt);
void	setphilo_data(t_philo *philo, t_fork *forks, t_data *data);
int		_create_tr(pthread_t *threads, t_philo *philo);
int		_init_mutexes(t_fork *forks, t_data *data);
int		_wait_threads(pthread_t *threads, t_data *data);
void	destro_philos(t_philo *philos, t_data *data);
void	_free_data(t_philo *philos, t_fork *forks, pthread_t *threads);

#endif
