#include "minilibx-linux/mlx.h"

int main()
{ 
	void *mlx_connection;
	void *mlx_window;

	mlx_connection = mlx_init(); 
	mlx_window = mlx_new_window(mlx_connection, 500, 500, "My 1* So_long");

	mlx_loop(mlx_connection);

}