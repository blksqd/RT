#include "RT.h"

/*
** ----------------------------------------------------------------------------
** Recursive function which casts a ray through the scene. Type of ray will
** influence what informations it will receive (ray_origin / ray_direction),
** and when a ray has hit it's target or is being casted too many times, 
** calls a shading function to color the pixel of which the ray is associated
** with.
**
** @param {t_rt *} rt - Main structure for RT.
** @param {t_ray *} ray - Ray that has to be casted from a point to another.
** ----------------------------------------------------------------------------
*/

uint32_t			rt_cast_ray(t_rt *rt, t_ray *ray)
{
	++ray->depth;
	if (ray->ray_type == PRIMARY_RAY)
		get_primary_ray_info(rt, ray);
	rt_ray_dispatching(rt, ray);
	if (ray->ray_type == END_RAY || ray->depth >= MAX_DEPTH)
		return (ray->pix_color);
	return (rt_cast_ray(rt, ray));
}

/*
** ----------------------------------------------------------------------------
** Main rendering function for the scene, parses all the pixels and casts rays
** through them to check for intersection with objects, and get informations
** on light, shadows and overall shade applied on the color of said object.
**
** @param {t_rt *} rt - Main structure for RT.
** ----------------------------------------------------------------------------
*/

void				rt_render(t_rt *rt)
{
	int		i;
	t_ray	current_ray;

	i = -1;
	while (++i < (HEIGHT * WIDTH))
	{
		current_ray.depth = -1;
		current_ray.pix_nb = i;
		current_ray.ray_type = PRIMARY_RAY;
		current_ray.pix_color = DEFAULT_BACKGROUND[i];
		FRAMEBUFF[i] = rt_cast_ray(rt, &current_ray);
	}
}