/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:34:17 by mgenoves          #+#    #+#             */
/*   Updated: 2024/11/12 10:30:36 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/pipex.h"

void	init_stack(t_pipex *pipex, char **argv, char **envp, int argc)
{
	int	i;

	pipex->infile = open(argv[1], O_RDONLY | O_NONBLOCK);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->envp = envp;
	pipex->argv = argv;
	pipex->path = ft_search_path(envp);
	pipex->num_cmds = argc - 3;
	pipex->cmd = (char ***)ft_calloc(argc - 3, sizeof(char **));
	if (!pipex->cmd)
		return ;
	i = -1;
	if (check_all_cmds(pipex, argv))
	{
		free_pipex(pipex);
		exit(1);
	}
	while (++i < argc - 3)
		pipex->cmd[i] = return_valid_cmd(pipex, argv[i + 2]);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
	free(pipex->path);
	i = -1;
	while (++i < pipex->num_cmds)
		free_str(pipex->cmd[i]);
	free(pipex->cmd);
	free(pipex);
}

char	**ft_search_path(char **envp)
{
	int		i;
	char	**str0;
	char	**str1;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			str0 = ft_split(envp[i], '=');
			if (!str0)
				return (NULL);
			free(str0[0]);
			str1 = ft_split(str0[1], ':');
			if (!str1)
				return (NULL);
			free(str0[1]);
			free(str0);
			break ;
		}
	}
	add_slash(str1);
	return (str1);
}

void	add_slash(char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (str[++i])
	{
		tmp = ft_strdup(str[i]);
		free(str[i]);
		str[i] = ft_strjoin(tmp, "/");
		free(tmp);
	}
}
