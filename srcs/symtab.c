/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 10:21:27 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/04 09:46:33 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static char		get_symchar(uint8_t ntype)
{
	char		symchar;

	if (ntype & N_STAB)
		return (-1);
	if (IS_UNDF(ntype))
		symchar = 'u';
	else
		symchar = 't';
	if (IS_EXT(ntype))
		symchar = ft_toupper(symchar);
	return (symchar);

}

static void		print_entry(uint64_t symvalue, char symchar, char *symstr)
{
	if (symchar == 'U' || symchar == 'u')
		(void)ft_printf("%16s %c %s\n", "", symchar, symstr);
	else
	{
		(void)ft_printf("%016llx %c %s\n", symvalue, symchar, symstr);
	}
}

t_symtab	symtab_add(uint64_t symvalue, char symchar, char *symstr)
{
	t_symtab	new;

	new.symvalue = symvalue;
	new.symchar = symchar;
	new.symstr = symstr;
	return (new);
}

static void		symtab_sort(t_symtab *symtab, uint32_t nsyms)
{
	uint32_t				i;
	uint32_t				j;
	t_symtab				tmp;

	i = 0;
	while (i < nsyms - 1)
	{
		j = 0;
		while (j < nsyms - i - 1)
		{
			if (ft_strcmp(symtab[j].symstr, symtab[j + 1].symstr) > 0)
			{
				tmp = symtab[j];
				symtab[j] = symtab[j + 1];
				symtab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		symtab_print(t_symtab *symtab, uint32_t nsyms)
{
	uint32_t				i;
	uint64_t				symvalue;
	char					symchar;
	char					*symstr;

	i = 0;
	while (i < nsyms)
	{
		symvalue = symtab[i].symvalue;
		symchar = symtab[i].symchar;
		symstr = symtab[i].symstr;
		if (symchar != -1)
			(void)print_entry(symvalue, symchar, symstr);
		i++;
	}
}

void			symtab_dump(uint32_t nsyms, uint32_t symoff, uint32_t stroff, void *ptr)
{
	uint32_t				i;
	char					*strtable;
	struct nlist_64			*nlist;
	t_symtab				symtab[nsyms];

	nlist = ptr + symoff;
	strtable = ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		symtab[i] = symtab_add(nlist[i].n_value, get_symchar(nlist[i].n_type), strtable + nlist[i].n_un.n_strx);
		i++;
	}
	(void)symtab_sort(symtab, nsyms);
	(void)symtab_print(symtab, nsyms);
}
