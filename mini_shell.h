/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybiouss <aybiouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:36:00 by sben-ela          #+#    #+#             */
/*   Updated: 2023/02/10 11:36:54 by aybiouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINI_SHELL_H
# define  MINI_SHELL_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<readline/readline.h>
#include	<readline/history.h>
#include	<fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <string.h>

typedef	struct	shell
{
	char			*cmd;
	/// type => infile = 0, outfile = 1, pipe = 2,cmd = 3;
	int				type;
	struct shell	*next;
	char	**cmds;
	char	**paths;
	char	*argv;
}	t_shell;

int		ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	**ft_split(char const *str, char c);
void    ft_execute(t_shell *shell, char **env);

//utils
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif

