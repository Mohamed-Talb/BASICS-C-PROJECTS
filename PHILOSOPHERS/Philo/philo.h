/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaleb <mtaleb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:50:34 by mtaleb            #+#    #+#             */
/*   Updated: 2025/07/26 11:44:40 by mtaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INCLUDES
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// ERRORS
# define ERR_INVALID_ARG_COUNT "Error: Invalid number of arguments.\n"
# define ERR_NON_NUMERIC_ARG "Error: All arguments must be positive integers.\n"
# define ERR_ARG_ZERO_OR_NEGATIVE "Error: Arguments must be greater than zero.\n"

# define THREAD_ERROR "Error: faild to creat thread\n"
# define MALLOC_ERROR "Error: memory allocation faild\n"
# define MUTEX_ERROR "Error: Failed to initialize mutex\n"

// TAKE FORKS MESSAGES
# define TAKE_RFORK "has taken a right fork"
# define TAKE_LFORK "has taken a left fork"

// STRUCTURES
typedef struct s_philo
{
	int				tid;
	int				xeat;
	int				rfork;
	int				lfork;
	int				start;
	int				access;
	size_t			order;
	size_t			lastmeal;
	size_t			duration;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	bool			dead;
	size_t			tdie;
	size_t			teat;
	size_t			tsleep;
	size_t			starttime;
	int				all;
	int				turns_nb;
	int				numofphilos;
	int				mealsrequired;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	all_mutex;
	pthread_mutex_t	printlock;
	pthread_mutex_t	xeat_mutex;
	pthread_mutex_t	death_mutex;
}					t_data;

// INITIALIZATION
int					initforks(t_data *data);
int					initphilo(t_data *data);
int					init_data(t_data *data);
int					parse(int ac, char **av, t_data *data);

// SIMULATION UTILES
int					start(t_data *data);
void				*routine(void *arg);
void				death_checker(t_data *data);
void				predict_simulation(t_data *data);

// ROUTINE UTILES
int					eating(t_philo *philo);
void				sleeping(t_philo *philo);
void				take_forks(t_philo *philo);
void				thinking(t_philo *philo, int ch);

// MANAGMENT
size_t				get_time_in_ms(void);
void				free_data(t_data *data);
int					ft_usleep(t_philo *philo, size_t milli, size_t start);

// OTHERS
int					ft_isdigit(int c);
void				manageexit(t_data *data);
size_t				sizet_atoi(const char *nptr);
void				errors(t_data *data, char *error);
void				safeprint(char *str, t_philo *philo);

#endif
