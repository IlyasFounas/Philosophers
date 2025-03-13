/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:48:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/13 17:01:20 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			BUFFER_SIZE = 10;

static int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	ft_strcat_gnl(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (src[i] && src[i] != '\n')
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	*get_rest(int fd, char *tmp)
{
	int		verif_read;
	char	*line;

	while (ft_strchr_gnl(tmp, "\n") == 0)
	{
		verif_read = read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE] = '\0';
		if (verif_read == -1)
			exit(1);
		line = malloc((ft_strlen_gnl(tmp) + 1) * sizeof(char));
		if (!line)
			exit(1);
		ft_strcat_gnl(tmp, line);
        
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	tmp[BUFFER_SIZE + 1];

	line = get_rest(fd, tmp);
	return (line);
}

int	main(void)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open("philo.c", O_RDONLY);
	line = get_next_line(fd);
	while (i < 100)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
