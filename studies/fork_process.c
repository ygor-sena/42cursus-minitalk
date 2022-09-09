/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:28:01 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/09 22:35:02 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	/* cria um processo-filho */
	pid = fork();
	if (pid < 0)
	{
		/* um erro ocorreu */
		fprintf(stderr, "Fork Failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		/* processo-filho */
		execlp("/bin/ls", "ls", NULL);
	}
	else
	{
		/* processo-pai */
		/* o pai esperará que o filho seja concluído */
		wait(NULL);
		printf("Child Complete\n");
	}
	return (0);
}
