/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:17:46 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:35:13 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define WRITING "/is_writing"
# define FORKS "/forks"
# define START_SIMULATION "/start_simulation"
# define SEM_CHECK "/checking"

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int		nbr;
	int		time2die;
	int		time2eat;
	int		time2sleep;
	int		eattimes;
	size_t	start;
	sem_t	*printing;
	sem_t	*forks;
	sem_t	*start_sim;
	sem_t	*check;
}			t_data;

typedef struct s_philo
{
	int		id;
	t_data	*data;
	size_t	last_meal;
}			t_philo;

int			ft_atoi(char *str);
size_t		ft_time(void);
void		*thread_routine(void *arg);
size_t		ft_time_passed(size_t start);
int			ft_sleep(size_t time);
void		__routine(t_philo *philo);
void		print_status(t_data *data, int id, char *msg, char c);
bool		_validate(t_data *dt, int ac);
void		set_data(t_data *data, char **av);
t_philo		philo_data(t_data *dt, int i);
int			_alloc2philos(t_philo **philos, t_data *dt, int **childs);
void		_unlink_sems(void);
void		_free_resources(int *children, t_philo *philos);
void		_one_handler(t_data *dt);

#endif