#include <nm.h>

static void	*load_file(char *filename)
{
	int			fd;
	struct stat	buf;
	char		*ptr;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putendl_fd("open failed", 2);
		return ((void *)EXIT_FAILURE);
	}
	if (fstat(fd, &buf) < 0)
	{
		ft_putendl_fd("fstat failed", 2);
		return ((void *)EXIT_FAILURE);
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_putendl_fd("mmap failed", 2);
		return ((void *)EXIT_FAILURE);
	}
	return (ptr);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl("");
		return (EXIT_FAILURE);
	}
	while (*av)
	{
		ptr = load_file(*av);
		if (ptr)
		{
			nm(ptr);
			if (munmap(ptr, buf.st_size) < 0)
				ft_putendl_fd("munmap failed", 2);
		}
		av++;
	}
	return (EXIT_SUCCESS);
}
