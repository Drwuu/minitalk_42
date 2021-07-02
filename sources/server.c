/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:43:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/07/02 16:34:34 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	g_packet.buffer = 0;
	g_packet.bit_index = 0;
	if (signal(SIGUSR1, listen_0) == SIG_ERR)
		ft_error(NULL, NULL, NULL, "An error occured\n");
	if (signal(SIGUSR2, listen_1) == SIG_ERR)
		ft_error(NULL, NULL, NULL, "An error occured\n");
	while (TRUE)
		pause();
	return (0);
}
