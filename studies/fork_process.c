/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 22:28:01 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/27 01:47:41 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	/* Create a child process */
	pid = fork();
	if (pid < 0)
	{
		/* An error occured */
		fprintf(stderr, "Fork Failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		/* Child process */
		execlp("/bin/ls", "ls", NULL);
	}
	else
	{
		/* Parent process */
		/* Parent waits child process until its end */
		wait(NULL);
		printf("Child Complete\n");
	}
	return (0);
}
