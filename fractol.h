#ifdef FRACTOL_H
# define FRACTOL_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define HEIGHT 1000
# define WIDTH 13000
# define MOVE 0.1
# define ZOOM 1.3
# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define SHIFT 257

typedef	struct s_lim
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	cr;
	double	cim;
}	t_lim;

typedef	struct s_img
{
	void *ipt;
	char **ppt;
	int	bits;
	int	endian;
	int	line;
}	t_img

typedef struct s_data
{
	void	*init;
	void	*wwin;
	int	type;
	double	x;
	double	y;
	int	i;
	int	color;
	t_lim	lim;
	t_img	img;	
}	t_data;

void	initialize(char *argv, t_dat *frac);
int	ft_free(t_dat *frac);
void	parse(int ac, char **argv, t_data *frac);
int	fractal_draw(t_data *frac);

void	ft_pixel_put(t_data *frac, int a, int b, int color);
int	ft_color(t_data *frac);
int	ft_read_keys(int key, t_data *frac);
int	ft_mouse_hook(int key, int x, int y, t_data *frac);


#endif


