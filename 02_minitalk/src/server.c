/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:24:23 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/20 13:46:01 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	get_bit_value(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	else if (signum == SIGUSR2)
		return (1);
	return (0);
}

static void	reset_client(t_msg *msg, pid_t pid)
{
	msg->client_pid = pid;
	msg->c = 0;
	msg->bit_count = 0;
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static t_msg	g_msg;
	int				bit_val;

	(void)context;
	if (g_msg.client_pid != info->si_pid)
		reset_client(&g_msg, info->si_pid);
	bit_val = get_bit_value(signum);
	g_msg.c = g_msg.c | (bit_val << g_msg.bit_count);
	g_msg.bit_count++;
	if (g_msg.bit_count == 8)
	{
		write(1, &g_msg.c, 1);
		if (!g_msg.c)
		{
			write(1, "\n", 1);
			g_msg.c = 0;
			g_msg.bit_count = 0;
			kill(info->si_pid, SIGUSR1);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		g_msg.c = 0;
		g_msg.bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("server PID is %d\n", getpid());
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		exit(ft_printf("Signal handler setup failed\n"));
	while (1)
		pause();
	return (0);
}
