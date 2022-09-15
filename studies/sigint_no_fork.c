/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_no_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:31:19 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/15 22:37:21 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include<stdio.h>

/* Handler function */
void	handler(int sig)
{
	printf("Receive signal: %u\n", sig);
}

int	main(void)
{
	struct sigaction	sig_a;
    /* Initialize the signal handler structure */
	sig_a.sa_handler = handler;
	sigemptyset(&sig_a.sa_mask);
	sig_a.sa_flags = 0;
    /* Assign a new handler function to the SIGINT signal */
	sigaction(SIGINT, &sig_a, NULL);
    /* Block and wait until a signal arrives */
	while (1)
	{
		sigsuspend(&sig_a.sa_mask);
		printf("loop\n");
	}
	return (0);
}
