#include "hotel.h"

int	parser(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (!ft_isdigit(prompt[i]) && prompt[i] != ' ' && prompt[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	room_exist(t_room *rooms, long num)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->num == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_reserved(t_room *rooms, long num)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->num == num)
		{
			if (tmp->expired_reservation > get_time())
			{
				printf("this room is reserved! it will be free in %ld days choose another room\n", ((((tmp->expired_reservation - get_time()) / 1000) / 3600) / 24) + 1);
				return (1);
			}
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}
