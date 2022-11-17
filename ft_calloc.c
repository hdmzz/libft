#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	buff = malloc(size * count);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (count * size));
	return (buff);
}
