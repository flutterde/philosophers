/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:11:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/10 18:40:44 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_children(int count, int *pids)
{
	int	i;

	i = 0;
	while (i < count)
		kill(pids[i++], SIGKILL);
}

void	_waitpids(t_data *data, int *childs)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->nbr)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_children(data->nbr, childs);
			break ;
		}
		i++;
	}
}

int	_handler(t_data *dt)
{
	int		i;
	pid_t	pid;
	int		*children;
	t_philo	*philos;

	i = 0;
	_alloc2philos(&philos, dt, &children);
	while (i < dt->nbr)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			__routine(&philos[i]);
		else if (pid > 0)
			children[i] = pid;
		i++;
	}
	i = 0;
	while (i++ < dt->nbr)
		sem_post(dt->start_sim);
	_waitpids(dt, children);
	_free_resources(children, philos);
	return (1);
}

bool	semaphore_handler(t_data *data)
{
	_unlink_sems();
	data->printing = sem_open(WRITING, O_EXCL | O_CREAT, 0640, 1);
	if (!data->printing)
		return (printf("Can't Open Semaphore (WRITING)\n"), false);
	data->forks = sem_open(FORKS, O_EXCL | O_CREAT, 0640, data->nbr);
	if (!data->forks)
		return (printf("Can't Open Semaphore (FORKS)\n"), false);
	data->start_sim = sem_open(START_SIMULATION, O_EXCL | O_CREAT, 0640, 0);
	if (!data->start_sim)
		return (printf("Can't Open Semaphore (START_SIMULATION)\n"), false);
	data->check = sem_open(SEM_CHECK, O_EXCL | O_CREAT, 0640, 1);
	if (!data->check)
		return (printf("Can't Open Semaphore (SEM_CHECK)\n"), exit(1), false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Number of args not valid.\n"), 1);
	set_data(&data, av);
	if (!_validate(&data, ac))
		return (printf("The args are not Valid!\n"));
	if (data.nbr == 1)
		return (_one_handler(&data), 1);
	semaphore_handler(&data);
	_handler(&data);
	sem_close(data.printing);
	sem_close(data.forks);
	sem_close(data.start_sim);
	sem_close(data.check);
	_unlink_sems();
	return (0);
}
