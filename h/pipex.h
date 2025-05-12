/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:24:11 by mgenoves          #+#    #+#             */
/*   Updated: 2024/11/12 09:55:17 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**envp;
	char	**argv;
	char	**path;
	char	***cmd;
	int		num_cmds;
	int		temp_file_status;
}	t_pipex;

void	init_stack(t_pipex *pipex, char **argv, char **envp, int argc);
void	free_pipex(t_pipex *pipex);
char	**ft_search_path(char **envp);
int		check_valid_cmd(t_pipex *pipex, char *cmd);
char	**return_valid_cmd(t_pipex *pipex, char *cmd);
void	add_slash(char **str);
int		check_all_cmds(t_pipex *pipex, char **argv);
void	free_str(char **str);

void	ft_pipex(t_pipex *pipex);
void	child_process(int i, int *pipefd, t_pipex *pipex);
void	last_cmd(t_pipex *pipex);
void	parent_process(int *pipefd);

#endif
