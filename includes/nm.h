/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:08:56 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/03 09:04:55 by pdeguing         ###   ########.fr       */
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

void				nm(void *file);

void				print_output(int nsyms, int symoff, int stroff, void *ptr);

#endif
