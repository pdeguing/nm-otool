/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:08:56 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/04 09:20:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <libft.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>

# define IS_UNDF(a)		((a & N_TYPE) == N_UNDF)
# define IS_EXT(a)		((a & N_EXT))

typedef struct s_symtab		t_symtab;

struct						s_symtab
{
	uint64_t				symvalue;
	char					symchar;
	char					*symstr;
};

void						symtab_dump(uint32_t nsyms, uint32_t symoff, uint32_t stroff, void *ptr);

int							is_macho(void *ptr);

void						nm(void *ptr);


#endif
