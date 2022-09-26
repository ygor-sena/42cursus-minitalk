/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:56:42 by yde-goes          #+#    #+#             */
/*   Updated: 2022/09/26 20:26:50 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <string.h>

void	data_received(__attribute__((unused)) int sig)
{
	(void) sig;
	ft_putstr_fd("DATA RECEIVED BY SERVER\n", 1);
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction s_response;

	s_response.sa_handler = data_received;
	sigemptyset(&s_response.sa_mask);
	s_response.sa_flags = 0;
	sigaction(SIGUSR1, &s_response, NULL);
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf("Client is ok\n");
	kill(pid, SIGUSR1);
	ft_printf("Sent to server\n");
	ft_printf("Ending client\n");
	return (0);
}
