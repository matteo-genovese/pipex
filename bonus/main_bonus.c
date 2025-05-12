/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgenoves <mgenoves@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:27:17 by mgenoves          #+#    #+#             */
/*   Updated: 2024/11/12 10:30:43 by mgenoves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (0);
	pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (1);
	init_stack(pipex, argv, envp, argc);
	ft_pipex(pipex);
	free_pipex(pipex);
}
