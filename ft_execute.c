/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:28:01 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/10 11:42:44 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	error(char *str, int n)
{
	if (str)
	{
		ft_putstr_fd("Pipex : ", 2);
		ft_putstr_fd(strerror(n), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(n);
}

char	*get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	// printf("cmds : %s\n", cmd);
	if (ft_strchr(cmd, '/'))
		return (cmd);
	i = 0;
	// printf("cmds2 : %s\n", cmd);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		// printf("PATH : %s\n", path);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	**get_paths(char **env, t_shell *shell)
{
	char	**paths;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
		{
			paths = ft_split(env[i] + 5, ':');
			if (!paths)
				error("Split function failed", 1);
			return (paths);
		}
		i++;
	}
	ft_putstr_fd("Pipex : Command not found: ", 2);
	ft_putstr_fd(shell->cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
	return (NULL);
}

void	ft_execute(t_shell *shell, char **env)
{
	// while(shell)
	// {
	// 	printf("%s\n", shell->cmd);
	// 	shell = shell->next;
	// }
	printf("%s %d\n", shell->cmd, shell->type);
	printf("%s %d\n", shell->next->cmd, shell->type);
	printf("%s %d\n", shell->next->next->cmd, shell->type);
	shell->cmds = ft_split(shell->cmd, ' ');
	// printf("CMDSSS: %s\n", shell->cmds[0]);
	shell->paths = get_paths(env, shell);
	// printf("%s\n", shell->paths[0]);
	// printf("%s\n", shell->paths[1]);
	// printf("%s\n", shell->paths[2]);
	// printf("%s\n", shell->paths[3]);
	// printf("%s\n", shell->paths[4]);
	// printf("%s\n", shell->paths[5]);
	// printf("CMD : %s\n", shell->cmd);
	shell->argv = get_cmd(shell->paths, shell->cmds[0]);
	// printf("ARGV: %s\n", shell->argv);
	// if (!shell->cmd)
	// {
	// 	// free_paths(shell->paths);
	// 	ft_putstr_fd("Command not found: ", 2);
	// 	ft_putstr_fd(shell->cmd, 2);
	// 	ft_putstr_fd("\n", 2);
	// 	exit(127);
	// }
	// if (execve(shell->argv, shell->cmds, env) == -1)
	// 	error(NULL, errno);
}