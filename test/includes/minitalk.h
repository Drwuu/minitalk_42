/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:47:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/06/08 17:30:17 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*
**	STANDARD INCLUDES
*/

# include <signal.h>
# include "../libft/libft.h"

/*
**	STANDARD INCLUDES
*/

/*
**	START DEFINES
*/

typedef struct	s_packet
{
	char	buffer;
	short	bit_index;
}	t_packet;

/*
**	END DEFINES
*/

#endif
