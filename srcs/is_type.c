/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 08:25:42 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/04 08:35:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int		is_macho(void *ptr)
{
	uint32_t			magic;

	magic = ((struct mach_header *)ptr)->magic;
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (1);
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		return (1);
	return (0);
}
