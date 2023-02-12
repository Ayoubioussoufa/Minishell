/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-ela <sben-ela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:36:00 by sben-ela          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/12 17:18:56 by sben-ela         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2023/02/10 17:30:30 by aybiouss         ###   ########.fr       */
=======
/*   Updated: 2023/02/10 20:56:46 by sben-ela         ###   ########.fr       */
>>>>>>> 13883f809b57d13f1ae59b4926bb5fc8e4ab2985
>>>>>>> 7ebcd45e1e59ad676fdec1fe1ddf6f12c220bb25
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
#include	<sys/wait.h>
#include	<sys/errno.h>
#include	<string.h>

typedef	struct	files
{
	char *infile;
	char *oufile;
}	t_files;

typedef	struct	shell
{
	/// type => redirect_input = 0; redirect_output = 1; pipe = 2; cmd = 3; << = 4; >> = 5
	int				type;
	//char			*cmd;
	char			**cmds;
	char			**paths;
	char			*argv;
	struct shell	*next;
	t_files			*files;	
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
int	ft_isalpha(int c);
int count_redirect(char *line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_shell	*ft_lstnew(char *content, int type);
t_shell	*ft_lstlast(t_shell *lst);
void	ft_lstadd_back(t_shell **lst, t_shell *new);
t_shell *full_list(char *line);
int		count_char(char *str, char c);
int		*posi_ofsplit(char *line);
char 	*handle_pipe_between_couts(char *line);
int		handle_couts(t_shell *shell);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);

#endif

