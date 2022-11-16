#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needlen;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	needlen = strlen(needle);
	while (haystack[i] && (i + needlen - 1) < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j])
		{
			if (j == needlen - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
