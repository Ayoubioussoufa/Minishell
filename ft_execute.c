/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:28:01 by aybiouss          #+#    #+#             */
/*   Updated: 2023/02/10 20:17:36 by sben-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mini_shell.h"

// void	error(char *str, int n)
// {
// 	if (str)
// 	{
// 		ft_putstr_fd(strerror(n), 2);
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(str, 2);
// 		ft_putstr_fd("\n", 2);
// 	}
// 	exit(n);
// }

// char	*get_cmd(char **paths, char *cmd)
// {
// 	int		i;
// 	char	*tmp;
// 	char	*path;

// 	if (ft_strchr(cmd, '/'))
// 		return (cmd);
// 	i = 0;
// 	while (paths[i])
// 	{
// 		tmp = ft_strjoin(paths[i], "/");
// 		path = ft_strjoin(tmp, cmd);
// 		free(tmp);
// 		if (access(path, F_OK) == 0)
// 			return (path);
// 		free(path);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	**get_paths(char **env, t_shell *shell)
// {
// 	char	**paths;
// 	int		i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		if (ft_strnstr(env[i], "PATH", 4))
// 		{
// 			paths = ft_split(env[i] + 5, ':');
// 			if (!paths)
// 				error("Split function failed", 1);
// 			return (paths);
// 		}
// 		i++;
// 	}
// 	ft_putstr_fd("Command not found: ", 2);
// 	ft_putstr_fd(shell->cmd, 2);
// 	ft_putstr_fd("\n", 2);
// 	exit(127);
// 	return (NULL);
// }

// void	ft_execute(t_shell *shell, char **env)
// {
	// pid_t	pid;
	// int	ret = 0;
	// (void)env;
	
	// int i = ft_lstsize(shell);
	// while (shell)
	// {
	// 	printf("%s \t %d\n", shell->cmd, shell->type);
	// 	shell = shell->next;
	// }
	// printf("%d\n", i);
	// if (pid == 0)
	// {
		// shell->cmds = ft_split(shell->cmd, ' '); //split the given commands
		// shell->paths = get_paths(env, shell); //get all paths
		// shell->argv = get_cmd(shell->paths, shell->cmds[0]); // join the path with the command
		// if (execve(shell->argv, shell->cmds, env) == -1) //execute the cmd in the given env
		// 	error(NULL, errno);
	// }
	// else
	// 	waitpid(-1, &ret, 0);
// }

// void	checktype(t_shell *shell, char **env)
// {
// 	if (shell->type == 0)
// 	{
// 		shell->infile = open(shell->next->cmd, O_RDONLY);
// 		dup2(shell->fd[0], 0);
// 		close(shell->fd[0]);
// 	}
// 	else if (shell->type == 2)
// 	{
// 		dup2(shell->fd[1], 1);
// 		close(shell->fd[1]);
// 	}
// 	if (shell->type == 3)
// 	{
// 		if (shell->next->type == 1)
// 		{
// 			shell->infile = open(shell->next->next->cmd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 			dup2(shell->infile, 1);
// 			close(shell->infile);
// 		}
// 		close(shell->fd[0]);
// 		close(shell->fd[1]);
// 		ft_execute(shell, env);
// 	}
// }

// void	checks(t_shell *shell, char **env)
// {
// 	pid_t	pid;

// 	pipe(shell->fd);//protection mnb3d
// 	pid = fork();//protection mnb3d
// 	if (pid == 0)
// 		checktype(shell, env);
// 	else
// 	{
// 		if (dup2(shell->fd[0], 0) == -1)
// 			error("dup2", errno);
// 		close(shell->fd[0]);
// 		close(shell->fd[1]);
// 	}
// }

// void	whatever(t_shell *shell, char **env)
// {
// 	while (shell)
// 	{
// 		checks(shell, env);
// 		shell = shell->next;
// 	}
// 	while (wait(NULL) != -1)
// 		;
// }

/*&& shell->type == 0)
		{
			shell->infile = open(shell->next->cmd, O_RDONLY);
			dup2(shell->fd[0], 0);
			close(shell->fd[0]);
		}
		else if (pid == 0 && shell->type == 2)
		{
			dup2(shell->fd[1], 1);
			close(shell->fd[1]);
		}
		if (pid == 0 && shell->type == 3)
		{
			if (shell->next->type == 1)
			{
				shell->infile = open(shell->next->next->cmd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				dup2(shell->infile, 1);
				close(shell->infile);
			}
			ft_execute(shell, env);
		}
		else
		{
			shell = shell->next;
			printf("%d\n", ret++);
		}
	}*/