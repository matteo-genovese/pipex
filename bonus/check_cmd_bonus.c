/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:35:32 by mgenoves          #+#    #+#             */
/*   Updated: 2024/11/12 10:30:38 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/pipex.h"

int	check_valid_cmd(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*str;

	i = -1;
	while (pipex->path[++i])
	{
		str = ft_strjoin(pipex->path[i], cmd);
		if (access(str, F_OK) == 0)
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}

char	**return_valid_cmd(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*str;
	char	**s;

	i = -1;
	while (pipex->path[++i])
	{
		s = ft_split(cmd, ' ');
		if (!s)
			return (NULL);
		str = ft_strdup(s[0]);
		if (!str)
			return (NULL);
		free(s[0]);
		s[0] = ft_strjoin(pipex->path[i], str);
		free(str);
		if (access(s[0], F_OK) == 0)
			return (s);
		free_str(s);
	}
	return (NULL);
}

int	check_all_cmds(t_pipex *pipex, char **argv)
{
	int		i;
	int		flag;
	char	**cmds;

	i = -1;
	flag = 0;
	while (++i < pipex->num_cmds)
	{
		cmds = ft_split(argv[i + 2], ' ');
		if (!check_valid_cmd(pipex, cmds[0]))
		{
			ft_putstr_fd("Error: ", 2);
			ft_putstr_fd(argv[i + 2], 2);
			ft_putstr_fd(" is not a valid command\n", 2);
			flag = 1;
		}
		free_str(cmds);
	}
	return (flag);
}

void	free_str(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}
