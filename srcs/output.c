/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:23:54 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/03 09:04:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static char		get_symchar(uint32_t ntype)
{
	char		symchar;

	if (IS_UNDF(ntype))
		symchar = 'u';
	else
		symchar = 't';
	if (IS_EXT(ntype))
		symchar = ft_toupper(symchar);
	return (symchar);

}

static void		print_entry(uint32_t symvalue, char symchar, char *symstr)
{
	if (symchar == 'U' || symchar == 'u')
		(void)ft_printf("%16s %c %s\n", "", symchar, symstr);
	else
	{
		(void)ft_printf("%016llx %c %s\n", symvalue, symchar, symstr);
	}
}

void	print_output(int nsyms, int symoff, int stroff, void *ptr)
{
	int						i;
	char					*strtable;
	struct nlist_64			*nlist;
	uint32_t				symvalue;
	char					symchar;
	char					*symstr;

	nlist = ptr + symoff;
	strtable = ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		symvalue = nlist[i].n_value;
		symchar = get_symchar(nlist[i].n_type);
		symstr = strtable + nlist[i].n_un.n_strx;
		(void)print_entry(symvalue, symchar, symstr);
		i++;
	}
}
