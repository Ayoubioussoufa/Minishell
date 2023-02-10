#include "mini_shell.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

int		ft_strcmp(char *s1, char *s2)
{
 	int	i;
 
 	i = 0;
 	while (s1[i] == s2[i] && s1[i] && s2[i])
 		i++;
 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_strchr (char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return(1);
	}
	return(0);
}
