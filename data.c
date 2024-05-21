#include "hotel.h"

void	get_data(char *buffer, t_room **rooms)
{
	t_room	*room;
	t_room	*tmp;
	char	**splited;
	int		i;

	i = 0;
	tmp = *rooms;
	room = malloc(sizeof(t_room));
	splited = ft_split(buffer, ':');
	while (splited[0][i])
	{
		if (ft_isdigit(splited[0][i]))
		{
			room->num = ft_atoi(splited[0] + i);
			break ;
		}
		i++;
	}
	i = 0;
	while (splited[1][i])
	{
		if (ft_isdigit(splited[1][i]))
		{
			room->expired_reservation = ft_atoi(splited[1] + i);
			break ;
		}
		i++;
	}
	room->next = NULL;
	if (!tmp)
	{
		*rooms = room;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = room;
	}
}

void	init_data(t_room **rooms)
{
	int		fd;
	char	*buffer;

	fd = open("data", O_RDWR, 0777);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		get_data(buffer, rooms);
		free(buffer);
	}
	close(fd);
}

void	update_data(t_room **rooms, long num, long days)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp)
	{
		if (tmp->num == num)
		{
			tmp->expired_reservation = get_time() + (days * 86400000);
			return ;
		}
		tmp = tmp->next;
	}
}

void	update_file(t_room *rooms)
{
	t_room	*room;
	char	*tmp;
	int		fd;

	room = rooms;
	fd = open("data", O_WRONLY | O_TRUNC);
	while (room)
	{
		tmp = ft_itoa(room->num);
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
		write(fd, " : ", 3);
		tmp = ft_itoa(room->expired_reservation);
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
		write(fd, "\n", 1);
		room = room->next;
	}
	close(fd);
}
