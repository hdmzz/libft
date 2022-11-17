#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		j;
	
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (*s1)
		new[j] = *s1++;
	while (*s2)
		new[j] = *s2++;
	new[j] = '\0';
	return (new);
}
