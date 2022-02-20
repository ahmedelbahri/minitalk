/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:41:12 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/02/20 21:48:12 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char	*str)
{
	int		i;
	char	*cast;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	cast = (char *)str;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	ft_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(1000);
		i++;
	}
}

void	ft_send(int pid, char *msg)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	j = -1;
	d = msg[j + 1];
	while (msg[++j])
	{
		while (i < 8)
		{
			d = 128 & msg[j];
			if (d == 0 && kill(pid, SIGUSR1) != -1)
				;
			else if (d == 128 && kill(pid, SIGUSR2) != -1)
				;
			else if (write(1, "wrong pid", 9))
				exit(0);
			usleep(300);
			msg[j] = msg[j] << 1;
			i++;
		}
		i = 0;
	}
	ft_end(pid);
}

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
		write(1, "message received", 16);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	signal(SIGUSR1, ft_received);
	if (argc == 3)
	{
		msg = argv[2];
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			write(1, "wrong pid", 9);
			exit(0);
		}
		ft_send(pid, msg);
	}
	else
		printf("You must have 3 arguments");
	return (0);
}
