#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;
	size_t	i;

	buff = malloc(size * count);
	if (!buff)
		return (NULL);
	i = 0;
	ft_bzero(buff, (count * size));
	return (buff);
}
