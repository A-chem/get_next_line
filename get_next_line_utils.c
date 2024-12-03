#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}
char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			a;

	a = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *) &s[i]);
	return (NULL);
}
char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	a;

	a = (char)c;
	res = NULL;
	while (*s)
	{
		if (*s == a)
			res = (char *)s;
		s++;
	}
	if (a == '\0')
		return ((char *)s);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*ptr;
	if (!s1)
		return NULL;
	dest = (char *) malloc(ft_strlen(s1) + 1);
	ptr = dest;
	if (!dest)
		return (NULL);
	while (*s1)
		*(dest++) = *(s1++);
	*dest = '\0';
	return (ptr);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	
    if (s1 == NULL)
        return (ft_strdup(s2));
	
	if (s2 == NULL)
        return (ft_strdup(s1));
	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = calloc(len + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
