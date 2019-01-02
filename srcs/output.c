/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:23:54 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/02 15:57:53 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void	print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	int						i;
	char					*strtable;
	struct nlist_64			*nlist;

	nlist = ptr + symoff;
	strtable = ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		ft_printf("%016llx %s\n", nlist[i].n_value, strtable + nlist[i].n_un.n_strx);
		i++;
	}
}
