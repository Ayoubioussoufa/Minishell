/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:36:00 by sben-ela          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/10 17:30:30 by aybiouss         ###   ########.fr       */
=======
/*   Updated: 2023/02/10 20:56:46 by sben-ela         ###   ########.fr       */
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
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
	/// type => redirect_input = 0; redirect_output = 1; pipe = 2; cmd = 3; << = delimiter; >> = redirect_output in append mode
	int				type;
	char			*cmd;
	char			**cmds;
	char			**paths;
	char			*argv;
	struct shell	*next;
}	t_shell;

void    ft_error(char *str);
int		ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	**ft_split(char const *str, char c);
void    ft_execute(t_shell *shell, char **env);
<<<<<<< HEAD
void	whatever(t_shell *shell, char **env);

=======
char	*parse_redirect(char *line);
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
//utils
int	handle_couts(t_shell *shell);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif

