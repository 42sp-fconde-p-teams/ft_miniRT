#include "./tests.h"
#include "../includes/miniRT.h"

// cylinder_normal is static, so the normal is tested via check_cylinders.

static int	vec_eq(t_vec3 a, t_vec3 b)
{
	return (fabs(a.x - b.x) < 1e-6
		&& fabs(a.y - b.y) < 1e-6
		&& fabs(a.z - b.z) < 1e-6);
}

static void	init_hit(t_hit *hit)
{
	hit->t = INFINITY;
	hit->type = (t_type)-1;
	hit->object = NULL;
}

static t_cylinder	make_cyl(t_vec3 center, t_vec3 axis, double d, double h)
{
	t_cylinder	cyl;

	cyl.coord_center = center;
	cyl.vector = axis;
	cyl.diameter = d;
	cyl.height = h;
	cyl.color = (t_rgb){255, 255, 255};
	cyl.next = NULL;
	return (cyl);
}

// Empty list: hit cannot be modified
int	should_not_change_hit_with_empty_list(void)
{
	t_hit	hit;
	t_ray	r;

	init_hit(&hit);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, NULL, &hit);

	if (hit.object == NULL && hit.type == (t_type)-1 && hit.t == INFINITY)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ray that misses the cylinder: hit cannot be modified
int	should_not_change_hit_on_miss(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;

	init_hit(&hit);
	cyl = make_cyl(vec3(10, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, &cyl, &hit);

	if (hit.object == NULL && hit.type == (t_type)-1 && hit.t == INFINITY)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Lateral: t=4, point (0,0,4), normal (0,0,-1), type/object fields populated
int	should_fill_hit_on_side(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;

	init_hit(&hit);
	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_CYLINDER && hit.object == &cyl
		&& fabs(hit.t - 4.0) < 1e-6
		&& vec_eq(hit.point, vec3(0, 0, 4))
		&& vec_eq(hit.normal, vec3(0, 0, -1)))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// +X-side lateral: radial normal (1,0,0)
int	should_have_radial_normal_on_positive_x_side(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;

	init_hit(&hit);
	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(10, 0, 5), vec3(-1, 0, 0));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_CYLINDER
		&& fabs(hit.t - 9.0) < 1e-6
		&& vec_eq(hit.point, vec3(1, 0, 5))
		&& vec_eq(hit.normal, vec3(1, 0, 0)))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Top cover: normal = +axis
int	should_have_axis_normal_on_top_cap(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;

	init_hit(&hit);
	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 10, 5), vec3(0, -1, 0));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_CYLINDER
		&& fabs(hit.t - 8.0) < 1e-6
		&& vec_eq(hit.point, vec3(0, 2, 5))
		&& vec_eq(hit.normal, vec3(0, 1, 0)))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Bottom cover: normal = -axis
int	should_have_negative_axis_normal_on_bottom_cap(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;

	init_hit(&hit);
	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, -10, 5), vec3(0, 1, 0));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_CYLINDER
		&& fabs(hit.t - 8.0) < 1e-6
		&& vec_eq(hit.point, vec3(0, -2, 5))
		&& vec_eq(hit.normal, vec3(0, -1, 0)))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// The normal vector for the side face is a unit vector perpendicular to the axis (the axis is
// tilted and not normalized—this serves as an exercise in normalization)
int	should_have_unit_normal_perpendicular_to_axis(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;
	t_vec3		axis;

	init_hit(&hit);
	cyl = make_cyl(vec3(0, 0, 5), vec3(1, 1, 0), 2.0, 4.0);
	axis = vec3_normalize(cyl.vector);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_CYLINDER
		&& fabs(vec3_length(hit.normal) - 1.0) < 1e-6
		&& fabs(vec3_dot(hit.normal, axis)) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// With two cylinders in the list (the farthest one first)
int	should_keep_closest_cylinder_in_list(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	far_cyl;
	t_cylinder	near_cyl;

	init_hit(&hit);
	far_cyl = make_cyl(vec3(0, 0, 10), vec3(0, 1, 0), 2.0, 4.0);
	near_cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	far_cyl.next = &near_cyl;
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, &far_cyl, &hit);

	if (hit.object == &near_cyl && fabs(hit.t - 4.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// The previous hit that is closer (t=1) cannot be overwritten by a cylinder at t=4
int	should_not_overwrite_closer_hit(void)
{
	t_hit		hit;
	t_ray		r;
	t_cylinder	cyl;
	int			sentinel;

	init_hit(&hit);
	hit.t = 1.0;
	hit.type = TYPE_SPHERE;
	hit.object = &sentinel;
	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	check_cylinders(r, &cyl, &hit);

	if (hit.type == TYPE_SPHERE && hit.object == &sentinel
		&& fabs(hit.t - 1.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_not_change_hit_with_empty_list);
	RUN_TEST(should_not_change_hit_on_miss);
	RUN_TEST(should_fill_hit_on_side);
	RUN_TEST(should_have_radial_normal_on_positive_x_side);
	RUN_TEST(should_have_axis_normal_on_top_cap);
	RUN_TEST(should_have_negative_axis_normal_on_bottom_cap);
	RUN_TEST(should_have_unit_normal_perpendicular_to_axis);
	RUN_TEST(should_keep_closest_cylinder_in_list);
	RUN_TEST(should_not_overwrite_closer_hit);
}
