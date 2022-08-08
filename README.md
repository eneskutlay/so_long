# So_long
### 2D game development using the MiniLibX library
**📙 MiniLibX - [Repo](https://github.com/42Paris/minilibx-linux)**

Used MiniLibX functions
-  ```void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param)```
-  ```int mlx_destroy_window(void *mlx_ptr, void *win_ptr)```
-  ```int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)```
-  ```void	*mlx_init()```
-  ```void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)```
-  ```void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)```
-  ```int mlx_loop(void *mlx_ptr);```
> Great resource for [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)


### How to run
- Clone this repository to your local
- Go to the directory you cloned and run the ```make``` command in it.
- If the program compiled without any problems, run the command ```./so_long maps/map1.ber```
- If all these steps are done correctly, the game will work.

![Screenshot](https://i.ibb.co/GtY1tyw/Ekran-Resmi-2022-08-08-O-O-6-30-29.png)
