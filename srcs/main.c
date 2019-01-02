/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:04:01 by pdeguing          #+#    #+#             */
/*   Updated: 2019/01/02 11:53:35 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	load_file(char *filename)
{
	int			fd;
	struct stat	buf;
	char		*ptr;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl_fd("open failed", 2);
		return ;
	}
	if (fstat(fd, &buf) < 0)
	{
		ft_putendl_fd("fstat failed", 2);
		return ;
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_putendl_fd("mmap failed", 2);
		return ;
	}
	nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		ft_putendl_fd("munmap failed", 2);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl("");
		return (EXIT_FAILURE);
	}
	av++;
	while (*av)
	{
		load_file(*av);
		av++;
	}
	return (EXIT_SUCCESS);
}
