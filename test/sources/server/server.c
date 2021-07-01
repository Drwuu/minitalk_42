/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:44:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/07/01 16:03:42 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_packet	g_packet;

void	next_bit(void)
{
	g_packet.bit_index++;
	if (g_packet.bit_index >= 8)
	{
		g_packet.bit_index = 0;
		write(1, &g_packet.buffer, 1);
		g_packet.buffer = 0;
	}
}

void	listen_0(int signal)
{
	(void)signal;
	g_packet.buffer <<= 1;
	next_bit();
}

void	listen_1(int signal)
{
	(void)signal;
	g_packet.buffer <<= 1;
	g_packet.buffer |= 1;
	next_bit();
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_puti_nl(pid);
	g_packet.buffer = 0;
	g_packet.bit_index = 0;
	signal(SIGUSR1, listen_0);
	signal(SIGUSR2, listen_1);
	while (TRUE)
		pause();
	return (0);
}
