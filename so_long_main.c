/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedfeld <mhedfeld@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:06:47 by mhedfeld          #+#    #+#             */
/*   Updated: 2023/11/22 15:32:39 by mhedfeld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data 
{
	void *img;
	void *mlx_ptr; 
	void *win_ptr; 
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	
}t_data;

int handle_input(int keysym, t_data *data)
{ 
	if (keysym == XK_Escape)
	{ 
		printf("The %d key (ESC) has been pressed\n\n", keysym); format:
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr); 

		free(data->img); 
		exit(1);  
	}
	return(0);
}

int main()
{
	void *mlx;
	t_data data;  
	void *mlx_window; 
	
	
	mlx = mlx_init();
    data.img = mlx_new_image(mlx, 700, 700);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.ll,&data.endian);
    mlx_window = mlx_new_window(mlx, 700, 700, "So_Long");
	mlx_put_image_to_window(mlx, mlx_window, data.img, 0, 0);
    mlx_loop(mlx);

		
}
