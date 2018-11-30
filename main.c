/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:40:17 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/29 22:26:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

/* Main basique */

void		ft_exit(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;
	int		len;
	int		i;

	i = 1;
	line = NULL;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("___Premier FD___ \n\n");
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_exit("Error: Can't open file");
		while ((code = get_next_line(fd, &line)) > 0)
		{
			len = ft_strlen(line);
			printf("%d\t - %d\t\t- |%s|\n", code, len, line);
			free(line);
		}
		i++;
		if (i < argc)
			printf("\n___Changement de FD___ \n\n");
	}
	printf("%d - |%s|\n", code, line);
	return (0);
}

/*
** Relire tous les commentaires avant de rendre
** Faire un join_free au lieu d un join
** Checker si enlever buff_size + 1 vs buff_size marche
** .
** .
** .
** .
** .
** .
** .
** Virer le main
** Verifier que author et auteur soit valide tous les deux
*/

/* Main pour STDIN */

/*
int			main(void)
{
	char	*line;
	int		fd;
	int		code;
	int		len;

	fd = 0;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("___FD___ \n\n");
	while ((code = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		printf("%d - %d - |%s|\n", code, len, line);
		free(line);
	}
	return (0);
}
*/

/*
int             main(int __unused ac, char **av)
{
    int     fd;
    char    *line;

    if ((fd = open(av[1], O_RDONLY)) == -1)
    {
        printf("which file bitch?\n");
        return (0);
    }  
   while (get_next_line(fd, &line) > 0)
    {
        printf("3 - %s\n", line);
        fflush(stdout);
        free(&line);
        line = NULL;
    }
    printf("4 - %d\n", get_next_line(fd, &line));
    return (0);
}
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


*/

/* Old Main */


/*
int             main(int __unused ac, char **av)
{
    int     fd;
    char    *line;

    if ((fd = open(av[1], O_RDONLY)) == -1)
    {
        printf("which file bitch?\n");
        return (0);
    }  
   while (get_next_line(fd, &line) > 0)
    {
        printf("3 - %s\n", line);
        fflush(stdout);
        free(&line);
        line = NULL;
    }
    printf("4 - %d\n", get_next_line(fd, &line));
    return (0);
}
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void		ft_exit(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}
*/
