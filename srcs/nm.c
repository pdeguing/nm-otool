/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:03:14 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/02 11:54:42 by pdeguing         ###   ########.fr       */
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
		ft_printf("%s\n", strtable + nlist[i].n_un.n_strx);
		i++;
	}
}

void	handle_64(void *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = ptr;
	ncmds = header->ncmds;
	lc = ptr + sizeof(struct mach_header_64);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}

}

void	nm(void *ptr)
{
	uint32_t		magic;

	magic = *(uint32_t *)ptr;
	if (magic == MH_MAGIC_64)
		handle_64(ptr);
}
