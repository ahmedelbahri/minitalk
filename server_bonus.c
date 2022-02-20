/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-bah <ahel-bah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:45:35 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/02/20 20:50:58 by ahel-bah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (power < 0)
	{
		return (0);
	}
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

int	bntodec(char *bn)
{
	int	i;
	int	res;
	int	p;

	i = 0;
	res = 0;
	p = 7;
	while (i < 8)
	{
		if (bn[i] == '1')
			res = res + ft_power(2, p);
		i++;
		p--;
	}
	return (res);
}

void	ft_print(char *bn, int *i, int pid)
{
	char	c;
	int		j;

	c = bntodec(bn);
	write(1, &c, 1);
	(*i) = 0;
	j = 0;
	while (bn[j] && bn[j] == 48 && j < 8)
	{
		if (j == 7)
			kill(pid, SIGUSR1);
		j++;
	}
}

// if kill(() == -1;
// 
void	handler(int sig, siginfo_t *siginfo, void *no)
{
	static char	bn[7];
	static int	i;
	static int	pid;

	no = NULL;
	if (!pid)
		pid = siginfo->si_pid;
	else if (pid != siginfo->si_pid)
	{
		i = 0;
		pid = siginfo->si_pid;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			bn[i] = 48;
		else if (sig == SIGUSR2)
			bn[i] = 49;
		i++;
	}
	if (i == 8)
		ft_print(bn, &i, pid);
}

int	main(void)
{
	struct sigaction	sa;

	printf("%d\n", getpid());
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
