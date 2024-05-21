#include "hotel.h"

int	main(void)
{
	t_room	*rooms;
	t_room	*tmp;
	char	*prompt;
	long	room_num;
	long	reservation_days;

	rooms = NULL;
	init_data(&rooms);
	printf("Welcome to our hotel\n\nhere is the available rooms:\n");
	tmp = rooms;
	while (tmp)
	{
		if (tmp->expired_reservation < get_time())
			printf("room %ld\n", tmp->num);
		tmp = tmp->next;
	}
	printf("choose an available room to get your reservation by giving the room number:\n");
	while (1)
	{
		prompt = get_next_line(0);
		if (!prompt)
		{
			printf("\nThank you for choosing us! Have a good day!\n");
			return 0;
		}
		if (parser(prompt))
		{
			write(1, "give a valid room number\n", 25);
			free(prompt);
			continue ;
		}
		room_num = ft_atoi(prompt);
		if (room_exist(rooms, room_num))
		{
			printf("the giving room doesn't exist! try a valid room\n");
			free(prompt);
			continue ;
		}
		if (is_reserved(rooms, room_num))
		{
			free(prompt);
			continue ;
		}
		free(prompt);
		break ;
	}
	printf("for how many days you want to reserve the room %ld:\n", room_num);
	while (1)
	{
		prompt = get_next_line(0);
		if (!prompt)
		{
			printf("\nThank you for choosing us! Have a good day!\n");
			return (0);
		}
		if (parser(prompt))
		{
			write(1, "give a valid room number\n", 25);
			free(prompt);
			continue ;
		}
		reservation_days = ft_atoi(prompt);
		free(prompt);
		printf("your room is reserved, here is your reservation key: %ld\n", get_time());
		break ;
	}
	printf("\nThank you for choosing us! Have a good day!\n");
	update_data(&rooms, room_num, reservation_days);
	update_file(rooms);
}
