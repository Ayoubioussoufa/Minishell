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

t_shell	*ft_lstnew(char *content, int type)
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
	t_shell	*shell;
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	shell = 0;
	// split line with pipe
	args = ft_split(line, '|');
	while (args[i])
	{
		// creat new node and add it to shell list(shell)
		ft_lstadd_back(&shell, ft_lstnew(args[i], 3));
		// this condition becouse we dont want a pipe after commands
		if (args[i + 1])
			// creat new node with pipe type between to command nodes
			ft_lstadd_back(&shell, ft_lstnew("|", 2));
		i++;
	}
	return(shell);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	char    *read;
	t_shell *shell;

	shell = NULL;
	while(1)
	{
	 	read = readline("Minishell> ");
		shell = parse_line(read);
		// ft_execute(shell, env);
		while(shell)
	{
		printf("%s\t %d\n", shell->cmd, shell->type);
		shell = shell->next;
	}
	}
	return 0;
}

// variable name -v = split(..., "found: ") to get the variable value !!
// < > ||| << >>