#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	// for casting
	unsigned char	uns_c;
	unsigned char *buff;
	
	//casting
	uns_c = (unsigned char)c;
	buff = (unsigned char *)s;
	
	i = 0;
	while(i < n)
	{
		if (buff[i] == uns_c)
			//  return a void pointer
			return ((void*) &buff[i]);
		i++;
	}

return (NULL);
}