/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:22 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/20 13:23:24 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

typedef struct s_msg
{
	unsigned char	c;
	int				bit_count;
	pid_t			client_pid;
}	t_msg;

//signal
void	handle_signal(int signum, siginfo_t *info, void *context);

//client
void	str_to_bit_send(char *str, pid_t pid);
int		pid_error_check(char *str);

#endif