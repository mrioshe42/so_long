#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX_FD 1024
# define PIXEL_SIZE 64

typedef enum s_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NUM_DIRECTIONS
}	t_directions;

typedef struct s_foe
{
	int		x;
	int		y;
	void	*img_ptr;
}		t_foe;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
}		t_map;

typedef struct s_player
{
	int		x;
	int		y;
	void	*p_img;
	int		width;
	int		height;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	bool		exit;
	int			num_foes;
	int			p_moves;
	int			num_items;
	int			p_items;
	int			x_exit;
	int			y_exit;
	t_map		*map;
	t_img		*img;
	t_foe		*foes;
	t_player	*player;
}		t_game;

void			check_exit(t_game *game);
void			open_exit(t_game *game);
void			check_lose(t_game *game);
void			check_valid_map(t_game *game);
void			check_valid_map_two(t_game *game, t_map *map_copy);
bool			check_valid_path(t_game *game, t_map *map_copy, int y, int x);
void			check_border(t_game *game);
int				check_num_components(t_game *game);
void			count_components(t_game *game, int *e_num, int *c_num,
					int *p_num);
void			check_components_map(t_game *game);
int				display_animation(t_game *game);
void			display_counter(t_game *game);
void			display_foes(t_game *game, int i);
void			display_background_and_items(t_game *game);
void			display_border(t_game *game);
void			load_image(t_game *game, void **img_ptr, const char *file);
void			xpm_to_window(t_game *game, char *file, int x, int y);
void			put_to_map(t_game *game, char c);
void			error_invalid_map(t_game *game, char *msg);
void			error_invalid_map_path(t_game *game, char *msg,
					t_map *map_copy);
void			free_stuff(t_game *game);
int				handle_input(int keysym, t_game *game);
void			init_map(char *file, t_game *game);
int				count_lines(int fd);
int				count_len(int fd);
int				check_map_name(char *name);
void			init_struct(t_game *game);
void			init_variables(t_game *game);
void			inti_map_data(t_game *game);
void			player_animation(t_game *game, int i);
void			read_ber_file(char *file, t_game *game);
void			handle_character(t_game *game, char buffer, int x, int y);
void			handle_foe(t_game *game, int x, int y);
void			dinit_map_row(t_game *game, int y);
void			update_enemy_position(t_game *game);
void			calculate_next_position(int *next_x, int *next_y,
					t_directions dir);
void			count_items(t_game *game);
void			free_map(t_game *game);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
void			update_player_position(t_game *game, int x, int y);
int				close_window(t_game *game);
void			clean_mlx(t_game *game);
void			win_banner(void);
void			lose_banner(void);
char			*get_next_line(int fd);
t_directions	get_random_direction(void);

#endif
