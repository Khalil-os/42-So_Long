#include "minilibx/mlx.h"
#include <stdlib.h>

int main(void)
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_w;
    int     img_h;

    mlx = mlx_init();
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 500, 400, "MiniLibX Example");
    if (!win)
        return (1);

    img = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_w, &img_h);
    if (!img)
        return (1);

    mlx_put_image_to_window(mlx, win, img, 100, 100);

    mlx_loop(mlx);
    return (0);
}