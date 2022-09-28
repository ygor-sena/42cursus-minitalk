/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:06:13 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/28 02:03:28 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_handler	*ft_signal(int signum, t_handler *handler)
{
	struct sigaction	action;
	struct sigaction	old_action;

	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	if (sigaction(signum, &action, &old_action) < 0)
		ft_putstr_fd("Signal error.\n", 1);
	return (old_action.sa_sigaction);
}

void	ft_kill(pid_t pid, int signum)
{
	int	rc;

	rc = kill(pid, signum);
	if (rc < 0)
		ft_putstr_fd("Kill error.\n", 1);
}
