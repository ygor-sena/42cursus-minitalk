/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:56:38 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/26 20:47:33 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void	bit_is_one(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;
	ft_putstr_fd("Bit is one\n", 1);
	kill(info->si_pid, SIGUSR1);
}

void	bit_is_zero(__attribute__((unused)) int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) info;
	(void) context;
	ft_putstr_fd("Bit is zero\n", 1);
}

int	main(void)
{
	struct sigaction s_true;
	struct sigaction s_false;

	ft_printf("Server PID is: %d\n", getpid());
	ft_printf("Server is ok\n");
	/* Signal 1 struct handler config */
	s_true.sa_sigaction = bit_is_one;
	sigemptyset(&s_true.sa_mask);
	s_true.sa_flags = SA_SIGINFO;
	/* Link handler and signal */
	sigaction(SIGUSR1, &s_true, NULL);
	s_false.sa_sigaction = bit_is_zero;
	sigemptyset(&s_false.sa_mask);
	s_false.sa_flags = SA_SIGINFO;
	while(1)
	{
		pause();
	}
	return (0);
}
