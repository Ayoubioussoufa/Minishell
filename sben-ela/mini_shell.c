#include "mini_shell.h"

t_shell	*ft_lstlast(t_shell *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_shell	*ft_lstnew(char **content, int type)
{
	t_shell	*x;

	x = malloc(sizeof(t_shell));
	if (!x)
		return (NULL);
	x->cmd = content;
    x->type = type;
	x->next = NULL;
	return (x);
}

int ft_size(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != ' ')
		i++;
	return(i);
}

char **ft_content(char *str)
{
	int i;
	int	j;
	char **dst;

	i = 0;
	j = 0;
	while(str[j])
	{
		if (str[j] == ' ')
			i++;
		j++;
	}
	dst = malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	while(*str && *str != '|')
	{
		while(*str == ' ')
			str++;
		if(*str)
			dst[i] = malloc(ft_size(str) + 1);
		while(*str && *str != ' ')
		{
			dst[i][j++] = *str++;
		}
		if(*str == ' ')
		{
			j = 0;
			i++;
		}
	}
	dst[i + 1]= 0;
	return(dst);
}

void	ft_lstadd_back(t_shell **lst, t_shell *new)
{
	t_shell	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

t_shell *parse_line(char *line)
{
	int i;
	t_shell *shell;
	i = 0;
	while (line[i])
	{
	   while (line[i] == ' ')
	       i++;
	    //if (line[i] == '|')
		//	ft_lstadd_back(&shell , ft_lstnew(ft_content(line + i), 2));
		if(line[i] != '|' && line[i])
		{
			ft_lstadd_back(&shell , ft_lstnew(ft_content(line + i), 3));
		}
		while(line[i] != '|' && line[i])
			i++;
		line += i;
		i++;
	}
	return(shell);
}
int main()
{
	char    *read;
	t_shell *shell;
	int i = 0;
	shell = NULL;
	while(1)
	{
	 	read = readline("Minishell> ");
		shell = parse_line(read);
		while(shell)
		{
			while(shell->cmd[i])
			{
				printf("+");
				printf("%s\n", shell->cmd[i++]);
			}
			i = 0;
			shell = shell->next;
		}
	}
	return 0;
}