/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:05:56 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 16:21:53 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/wr_malloc.h"

void	*ft_calloc(size_t size, size_t count)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = wrmalloc(count * size);
	if (!tab)
		return (NULL);
	while (i < count * size)
		tab[i++] = 0;
	return (tab);
}
