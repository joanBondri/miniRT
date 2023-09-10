/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:47:10 by jbondri           #+#    #+#             */
/*   Updated: 2021/02/09 12:12:21 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "libft/libft.h"
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <errno.h>
# define PI 3.14159265358

union				u_convert
{
	unsigned int	size;
	unsigned char	s[4];
	int				data;
	char			c[4];
};

typedef	struct		s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef	struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef	struct		s_param_frame
{
	t_mlx			mlx;
	t_img			img;
}					t_param_frame;

typedef struct		s_object
{
	char			type;
	void			*content;
}					t_object;

typedef	struct		s_camera
{
	t_vec			coo;
	t_vec			vector;
	t_vec			two_vector;
	t_vec			three_vector;
	int				fov;
	double			phi;
	double			rho;
	double			d;
}					t_camera;

typedef	struct		s_pixel
{
	int				color;
	t_object		*obj;
	double			res;
}					t_pixel;

typedef	struct		s_light
{
	t_vec			coo;
	double			power;
	int				color[3];
}					t_light;

typedef	struct		s_sphere
{
	t_vec			coo;
	double			r;
	int				color[3];
}					t_sphere;

typedef	struct		s_plane
{
	t_vec			coo;
	t_vec			vector;
	t_vec			vector1;
	t_vec			vector2;
	int				color[3];
}					t_plane;

typedef	struct		s_square
{
	t_vec			coo;
	t_vec			vector;
	t_vec			vector1;
	t_vec			vector2;
	double			border;
	int				color[3];
}					t_square;

typedef	struct		s_cylinder
{
	t_vec			coo;
	t_vec			vector;
	t_vec			vector1;
	t_vec			vector2;
	double			diameter;
	double			heigth;
	int				color[3];
}					t_cylinder;

typedef	struct		s_triangle
{
	t_vec			first_coo;
	t_vec			second_coo;
	t_vec			third_coo;
	int				color[3];

}					t_triangle;

typedef	struct		s_minirt
{
	int				r[2];
	int				a_color[3];
	double			a_pwr;
	t_list			*lights;
	t_list			*cameras;
	t_list			*objs;
	bool			show_light;
	bool			bmp;
	char			**data;
	t_camera		*cam;
	t_object		*on_focus;
}					t_minirt;

/*
** A useful variable that stores all the objects in the programme,
*/
t_minirt	g_rt;

void				assign_new_color(int color[3], t_light *li,
		t_object *obj, t_vec pt);
void				get_other_lights(t_vec pt, t_object *obj, int color[3]);
int					get_color_light(t_vec pt, t_object *obj);
bool				is_obj_between(t_vec ray, t_vec ori, t_object *obj);
void				get_color_object(int color_obj[3], t_object *obj);
void				get_intensity(double intensity[3], t_light *li, t_vec l);
int					ope_color(int obj, t_vec n, t_vec l, double intensity);
void				get_ambiant_color(int color[3], int color_obj[3]);
t_light				*get_next_light(t_light *actual);
t_object			*get_next_object(t_object *actual);
double				inter(t_vec ray, t_vec ori, t_object *obj);
void				put_plane(t_plane *pl, int fd);
void				put_camera(t_camera *cam, int fd);
void				put_cylinder(t_cylinder *cy, int fd);
void				put_triangle(t_triangle *tr, int fd);
void				put_light(t_light *l, int fd);
double				ft_abs(double f);
void				ft_putfloat_fd(float f, int fd);
void				put_color_fd(int c[3], int fd);
void				put_vector_fd(t_vec v, int fd);
void				put_square(t_square *a, int fd);
void				put_plane(t_plane *pl, int fd);
void				put_camera(t_camera *cam, int fd);
void				put_cylinder(t_cylinder *cy, int fd);
void				put_triangle(t_triangle *tr, int fd);
void				put_light(t_light *l, int fd);
void				setup_vector_cam(t_camera *c);
void				assign_camera(void);
void				assign_amblight(void);
char				**parse_file(int fd);
void				check_rt_param(void);
void				parsing(int fd, bool bmp_bool);
void				hub_type(void);
void				add_obj_list(void *item, char type);
void				assign_resolution(void);
void				assign_sphere(void);
t_object			*creat_obj(void *data, char type);
void				assign_light(void);
void				assign_triangle(void);
double				get_rho(t_vec vec);
double				get_phi(t_vec vec);
void				assign_plane(void);
void				assign_cylinder(void);
void				assign_square(void);
double				ft_atoi_f(char *str);
double				ft_atoi_f_secur(char *s);
int					ft_atoi_i(char *s);
char				*afterset(char *source, char *set);
t_vec				gen_p(t_vec origin, t_vec vec, double t);
void				assign_array(int tab[3], int src[3]);
int					check_ext(char *file, char *ext);
int					len_tab_string(char **strs);
t_vec				get_vector(char *vector);
t_vec				normalize_vector(t_vec tab);
double				extract_coo(char **str);
t_vec				get_coordinate(char *coordinates);
void				add_item_list(void *content, t_list **list);
void				get_color(char *colors, int tab[3]);
t_vec				ope_num(t_vec s, char c, double n);
t_vec				cross(t_vec s, t_vec t);
double				dot(t_vec f, t_vec s);
void				refresh_vector(t_camera *c);
t_vec				setup_two_vector(double phi, double rho);
t_vec				setup_three_vector(double phi, double rho);
int					move_sth(int keycode, t_param_frame *frame);
int					windows_key(t_param_frame *frame);
int					minimalize(t_param_frame *frame);
void				main_mlx(t_mlx mlx, t_img img);
t_camera			*get_next_cam(t_camera *actual);
t_vec				setup(int i, int j);
t_vec				ope(t_vec s, char c, t_vec t);
double				scalaire(t_vec f, t_vec s);
void				analyze_next_obj(t_vec ray, t_pixel *data, t_object *obj);
void				on_focus_color(int color[3]);
void				colision(t_vec ray, t_pixel *data);
void				next_frame(t_param_frame *obj);
int					clic_image(int keycode, int x, int y, t_param_frame *frame);
void				resize(void *mlx);
int					get_color_hexa(int tab[3]);
void				my_mlx_pixel_put(t_img img, int x, int y, int color);
void				go_mlx(void);
t_camera			*set_d_cam(t_camera *cam);
void				set_rt_null(void);
void				parsing(int fd, bool bmp_bool);
void				hub_type(void);
void				add_obj_list(void *item, char type);
void				assign_resolution(void);
void				assign_sphere(void);
void				assign_light(void);
void				assign_triangle(void);
void				assign_plane(void);
void				assign_cylinder(void);
void				assign_square(void);
void				assign_(void);
void				assign_camera(void);
void				assign_amblight(void);
char				**parse_file(int fd);
int					check_ext(char *file, char *ext);
int					len_tab_string(char **strs);
double				ft_atoi_f(char *str);
double				ft_atoi_f_secur(char *s);
int					ft_atoi_i(char *s);
char				*afterset(char *source, char *set);
t_vec				get_coordinate(char *coordinates);
t_vec				get_vector(char *vector);
void				add_item_list(void *content, t_list **list);
void				get_color(char *colors, int tab[3]);
t_vec				gen_p(t_vec origin, t_vec vec, double t);
t_vec				normalize_vector(t_vec tab);
void				ft_exit(char *s, int i);
void				free_minirt(void);
void				free_obj(void *obj);
void				free_tab_string(char **strs);
int					check_error_terminal(int argc, char **argv);
void				put_error(const char *error_str, int i);
void				resize(void *mlx);
int					get_color_hexa(int tab[3]);
void				my_mlx_pixel_put(t_img img, int x, int y, int color);
void				go_mlx(void);
t_camera			*set_d_cam(t_camera *cam);
t_camera			*get_next_cam(t_camera *actual);
t_vec				setup(int i, int j);
t_vec				ope(t_vec f, char c, t_vec s);
double				scalaire(t_vec f, t_vec s);
void				colision(t_vec ray, t_pixel *data);
void				setup_image(t_pixel	data, t_img *img, t_mlx *mlx);
void				main_mlx(t_mlx mlx, t_img img);
t_vec				setup_two_vector(double phi, double rho);
t_vec				setup_three_vector(double phi, double rho);
void				refresh_vector(t_camera *c);
double				col_sphere(t_vec ray, t_vec coo, t_sphere *sp);
double				col_plane(t_vec ray, t_vec coo, t_plane *pl);
double				col_cylinder(t_vec ray, t_vec coo, t_cylinder *cy);
double				col_square(t_vec ray, t_vec coo, t_square *sq);
double				col_triangle(t_vec ray, t_vec coo, t_triangle *tr);
t_vec				cross(t_vec s, t_vec t);
double				dot(t_vec f, t_vec s);
t_vec				ope_num(t_vec s, char c, double n);
t_vec				get_vect(t_vec f, t_vec s, t_vec t);
t_vec				get_normal(t_object *o, t_vec pt, t_vec coo);
void				on_focus_color(int color[3]);
void				assign_array(int tab[3], int src[3]);
int					mouvement_cam(int keycode);
void				mouvement_sphere(int keycode, t_sphere *sp);
void				mouvement_cylinder(int keycode, t_cylinder *cy);
void				next_frame(t_param_frame *obj);
void				mouvement_square(int keycode, t_square *sq);
void				mouvement_plane(int keycode, t_plane *pl);
void				mouvement_triangle(int keycode, t_triangle *tr);
int					get_color_light(t_vec pt, t_object *obj);
double				col_light(t_vec ray, t_vec coo, t_light *li);
void				mouvement_light(int keycode, t_light *li);
void				save(void);
void				gen_file(void);
t_object			*get_next_object(t_object *actual);
t_light				*get_next_light(t_light *actual);
t_camera			*get_next_cam2(t_camera *cam);
#endif
