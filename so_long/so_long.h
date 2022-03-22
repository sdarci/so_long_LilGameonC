/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:48:25 by sdarci            #+#    #+#             */
/*   Updated: 2022/03/22 11:48:35 by sdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_render_v
{
	void	*mlx;
	void	*win;
}	t_render_v;

typedef struct map_pars
{
	int			correct;
	char		*map;
	int			valid_len;
	int			width;
	int			col;
	int			player;
	int			exit;
	char		**mapspl;
	int			steps;
	int			i_w;
	int			i_h;
	void		*wall;
	void		*exitt;
	void		*pl;
	void		*floor;
	void		*items;
	void		*voidd;
	void		*pll;
	void		*exitwon;
	int			px;
	int			py;
	char		*test;
	t_render_v	*m2;
}	t_map;

void	parsing_map(int fd, t_map *params);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int i);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	*ft_free(void *ptr);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
int		valid_map(t_map *params);
void	play(t_map *mp);
char	**ft_split(char const *s, char c);
int		press(int keycode, t_map *m);
void	prepare(t_map *params);
int		ft_printf(const char *fmt, ...);
int		func1(const char *fmt1, va_list p);
size_t	ft_p(unsigned long int p);
size_t	hexahigh(unsigned long n);
size_t	hexalow(unsigned long n);
size_t	ft_putnbr( long int n);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
void	ft_col_put(t_map *p, t_render_v **w, int i, int j);
char	*ft_itoa(int n);
void	loop_f_map(t_map *p, t_render_v **w, int i, int j);
void	ft_put_win(t_map *p);
void	ft_sprite(t_map *m, int mv);
void	ft_print_string(t_map *m);
#endif
