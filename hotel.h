#ifndef HOTEL_H
# define HOTEL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include <time.h>

# include "get_next_line_bonus.h"

typedef struct s_room
{
	long			num;
	long			expired_reservation;
	struct s_room	*next;
}	t_room;

// Utils
char	**ft_split(const char *s, char c);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_itoa(long n);
long	get_time(void);

// Parser
int	is_reserved(t_room *rooms, long num);
int	room_exist(t_room *rooms, long num);
int	parser(char *prompt);

// Data
void	get_data(char *buffer, t_room **rooms);
void	init_data(t_room **rooms);
void	update_data(t_room **rooms, long num, long days);
void	update_file(t_room *rooms);

#endif
