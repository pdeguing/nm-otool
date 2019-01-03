/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:03:14 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/03 15:01:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void		handle_64(void *ptr)
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
			(void)symtab_dump(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}

}

void			nm(void *ptr)
{
	uint32_t		magic;

	magic = *(uint32_t *)ptr;
	if (magic == MH_MAGIC_64)
	{
		(void)handle_64(ptr);
	}
	else if (magic == MH_CIGAM_64)
	{
		(void)ft_putendl("swap64");
	}
	else if (magic == MH_MAGIC)
		ft_putendl("normal32");
	else if (magic == MH_CIGAM)
	{
		ft_putendl("swap32");
	}
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		ft_putendl("fat");
	else
		ft_putendl("unknown");
}
