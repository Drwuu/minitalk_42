/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:39:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/07/02 10:19:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_isdigit_str(const char *str)
{
	while (*str++)
		if (!(*str >= '0') && !(*str <= '9'))
			return (FALSE);
	return (TRUE);
}
