/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:23:58 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/20 10:06:18 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack;

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack |= 1;
	else if (sig == SIGUSR2)
		g_ack |= 2;
}

//sending least significant bit first.. ie rightmost
void	str_to_bit_send(char *str, pid_t pid)
{
	int	bit;
	int	i;

	i = 0;
	bit = 0;
	while (1)
	{
		while (bit < 8)
		{
			g_ack &= (~1);
			if (((str[i] >> bit) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			while ((g_ack & 1) == 0)
				pause();
		}
		if (str[i] == '\0')
			break ;
		bit = 0;
		i++;
	}
}

int	pid_error_check(char *str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			write(2, "Error, not a number\n", 20);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	num = ft_atoi(str);
	if (num <= 0 || num > INT_MAX)
		exit(write(2, "Error, invalid PID\n", 19));
	if (kill(num, 0) == -1)
	{
		if (errno == ESRCH)
			write(2, "Error: PID does not exist\n", 25);
		else if (errno == EPERM)
			write(2, "Error: Permission denied\n", 23);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
		exit(ft_printf("Error, usage should be: ./client <PID> <message> \n"));
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	pid_error_check(argv[1]);
	str_to_bit_send(str, pid);
	while ((g_ack & 2) == 0)
		pause();
	write (1, "server received msg\n", 20);
}
