/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 10:01:47 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/04 10:34:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static char		get_symchar_section()
{
	void			*section;
	char			*secname;
	char			*segname;

	section = get_section(ptr);
	if (!section)
		return ('s');
	sectname = ((struct section *)section)->sectname;
	segname = ((struct section *)section)->segname;
	if (!ft_strcmp(segname, SEG_TEXT) && !ft_strcmp(sectname, SECT_TEXT))
		return ('t');
	if (!ft_strcmp(segname, SEG_DATA))
	{
		if (!ft_strcmp(sectname, SECT_DATA))
			return ('d');
		if (!ft_strcmp(sectname, SECT_BSS))
			return ('b');
	}
	return ('s');
}

char		get_symchar(uint8_t ntype)
{
	char		symchar;

	if (ntype & N_STAB)
		return (-1);
	if (IS_UNDF(ntype))
	{
		if (nvalue == 0)
			symchar = 'u';
		else
			symchar = 'c';
	}
	else if (IS_PBUD(ntype))
		symchar = 'u';
	else if (IS_ABS(ntype))
		symchar = 'a';
	else if (IS_SECT(ntype))
		symchar = get_symchar_section();
	else if (IS_INDR(ntype))
		symchar = 'i';
	else
		return (-1);
	if (IS_EXT(ntype))
		symchar = ft_toupper(symchar);
	return (symchar);

}
