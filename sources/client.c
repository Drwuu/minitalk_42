/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:42:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/07/02 17:04:55 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(int pid, char c)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if (c >> bit_index & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(NULL, NULL, NULL, \
				"An error occured, you may use a valid PID\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(NULL, NULL, NULL, \
				"An error occured, you may use a valid PID\n");
		}
		usleep(150);
		bit_index--;
	}
}

void	send_str(int pid, char *str)
{
	size_t	char_index;

	char_index = 0;
	while (str[char_index])
	{
		send_char(pid, str[char_index]);
		char_index++;
	}
	ft_putstr_fd("Message sent\n", 1);
}

int	main(int argc, char **argv)
{
	long	pid;

	if (argc != 3 || !ft_isdigit_str(argv[1]))
	{
		ft_error(NULL, NULL, NULL, "Please use a valid PID\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid > INT_MAX || pid < INT_MIN)
	{
		ft_error(NULL, NULL, NULL, "Please use a valid PID\n");
		return (0);
	}
	send_str(pid, argv[2]);
	return (0);
}
