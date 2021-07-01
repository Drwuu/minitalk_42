/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:42:50 by lduplain          #+#    #+#             */
/*   Updated: 2021/07/01 16:03:55 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_char(int pid, char c)
{
	int	bit_index;

	bit_index = 7 + 1;
	while (--bit_index >= 0)
	{
		if (c >> bit_index & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
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
	int	pid;

	if (argc != 3)
		return (0);
	if (ft_strlen(argv[1]) > 11 && !is_numberstr(argv[1]))
		return (0);
	pid = ft_atoll(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
