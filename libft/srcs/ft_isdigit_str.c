/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:39:22 by lwourms           #+#    #+#             */
/*   Updated: 2021/07/02 16:40:27 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_isdigit_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!(str[i] >= '0' && str[i++] <= '9'))
			return (FALSE);
	return (TRUE);
}
