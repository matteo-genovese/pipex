/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:07:58 by mgenoves          #+#    #+#             */
/*   Updated: 2024/11/12 10:30:41 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/pipex.h"

void	ft_pipex(t_pipex *pipex)
{
	int		pipefd[2];
	pid_t	pid;
	int		i;

	dup2(pipex->infile, 0);
	i = -1;
	while (++i < pipex->num_cmds - 1)
	{
		if (pipe(pipefd) < 0)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			child_process(i, pipefd, pipex);
		else
			parent_process(pipefd);
	}
	last_cmd(pipex);
}

void	child_process(int i, int *pipefd, t_pipex *pipex)
{
	if (pipex->infile == -1)
	{
		perror("Error");
		free_pipex(pipex);
		exit(-1);
	}
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	execve(pipex->cmd[i][0], pipex->cmd[i], pipex->envp);
}

void	last_cmd(t_pipex *pipex)
{
	close(pipex->infile);
	if(pipex->outfile == -1)
	{
		perror("Error");
		free_pipex(pipex);
		exit(-1);
	}
	dup2(pipex->outfile, 1);
	execve(pipex->cmd[pipex->num_cmds - 1][0],
		pipex->cmd[pipex->num_cmds - 1], pipex->envp);
}

void	parent_process(int *pipefd)
{
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}
