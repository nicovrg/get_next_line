/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:10:09 by nivergne          #+#    #+#             */
/*   Updated: 2018/11/16 22:01:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char     *give_line(char *buff)
{
    size_t  i;

    i = 0;
    while (buff[i] != '\n')
        i++;
    return (ft_strsub(buff, 0, i));
}

int             get_next_line(const int fd, char **line)
{
    size_t          ret;
    char            buff[BUFF_SIZE + 1];
    static char     *store;

    if (!(fd || line || fd > 3))
        return (-1);
    ret = 0;
    store = malloc(1);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[ret] = '\0';
        store = ft_strjoin(store, buff);
        printf("1 - %s\n", buff);    
        if (ft_strchr(buff, '\n') != NULL)
        {
            *line = give_line(store);
            return (1);
        }
    }
    return (0);
}


int             main(int __unused ac, char **av)
{
    int     fd;
    char    *line;
    if ((fd = open(av[1], O_RDONLY)) == -1)
    {
        ft_putstr("couldn't open file\n");
        return (0);
    }
    get_next_line(fd, &line);
    printf("3 - %s\n", line);
    printf("4 - %d\n", get_next_line(fd, &line));
    return (0);
}

/*
** Relire tous les commentaires avant de rendre
** Faire un join_free au lieu d un join
** .
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