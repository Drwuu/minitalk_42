/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:42:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/07/02 15:54:42 by lwourms          ###   ########.fr       */
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
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
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
	send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	long	pid;

	if (argc != 3)
		return (0);
	if (!ft_isdigit_str(argv[1]))
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid > INT_MAX || pid < INT_MIN)
		return (0);
	send_str(pid, argv[2]);
	return (0);
}
