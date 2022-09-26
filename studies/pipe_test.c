/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:29:00 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/12 23:41:40 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int value = 5;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		/* processo-filho */
		value += 15;
		printf("CHILD: value = %d\n", value);
		return (0);
	}
	else if (pid > 0)
	{
		/* processo-pai */ 
		wait(NULL);
		printf("PARENT: value = %d\n", value);
		/* LINHA A */
		return (0);
	}
}