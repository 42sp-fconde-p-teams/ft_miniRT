#include "./tests.h"
#include "../includes/miniRT.h"

// Sets up a test cylinder (without a linked list).
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

// Vertical cylinder (Y-axis), center at z=5, radius=1, height=4.
// Straight ray along the side: hits at t=4
int	should_hit_cylinder_side_straight_on(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 4.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Lightning pointing in the opposite direction: it doesn't match
int	should_miss_cylinder_pointing_away(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, -1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Cylinder displaced on the X-axis: radius in the Z direction doesn't match
int	should_miss_cylinder_offset_in_x(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(10, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Cylinder behind the origin: both roots are negative; it should fail
int	should_miss_cylinder_behind_origin(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, -5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ray starting INSIDE the cylinder: should return the positive root (t=1)
int	should_hit_cylinder_from_inside(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 0), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 1.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Tangent radius: discriminant = 0; it must touch at a single point (t=5)
int	should_hit_cylinder_tangent(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(1, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 5.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Oblique intersection: must occur at some positive t
int	should_hit_cylinder_at_oblique_angle(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(-2, 0, 0), vec3(0.4472, 0, 0.8944));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& distance > 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// The radius passes above the cylinder (y=3, half the height = 2): it doesn't match.
int	should_miss_cylinder_above_height(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 3, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ray from top to bottom along the axis: hits the top cover (y=2) at t=8
int	should_hit_top_cap_from_above(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, 10, 5), vec3(0, -1, 0));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 8.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ray directed upwards along the axis: hits the bottom cap (y=-2) at t=8
int	should_hit_bottom_cap_from_below(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(0, -10, 5), vec3(0, 1, 0));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 8.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Vertical ray outside the radius of the cap (x=2 > r=1): no hit
int	should_miss_cap_outside_radius(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(2, 10, 5), vec3(0, -1, 0));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Non-normalized axis (0,5,0) should behave the same as (0,1,0): t=4
int	should_normalize_cylinder_axis(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 5, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 4.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Horizontal cylinder (X-axis): radius along the Z-axis hits the side at t=4
int	should_hit_horizontal_cylinder_side(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(1, 0, 0), 2.0, 4.0);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 4.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ray parallel to the axis (a = 0 in the quadratic equation): only the cap can be hit.
// Cap at x = -2, origin at x = -10: t = 8
int	should_hit_cap_when_ray_parallel_to_axis(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(1, 0, 0), 2.0, 4.0);
	r = ray(vec3(-10, 0, 5), vec3(1, 0, 0));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 8.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// The root near the side falls above the height, but the cap (t=5) is
// closer than the root far from the side (t=6.67): it should return t=5
int	should_prefer_cap_over_far_side_root(void)
{
	t_cylinder	cyl;
	t_ray		r;
	double		distance;

	cyl = make_cyl(vec3(0, 0, 5), vec3(0, 1, 0), 2.0, 4.0);
	r = ray(vec3(-3, 6, 5), vec3(0.6, -0.8, 0));

	if (intersect_cylinder(r, cyl, &distance) == EXIT_SUCCESS
		&& fabs(distance - 5.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_hit_cylinder_side_straight_on);
	RUN_TEST(should_miss_cylinder_pointing_away);
	RUN_TEST(should_miss_cylinder_offset_in_x);
	RUN_TEST(should_miss_cylinder_behind_origin);
	RUN_TEST(should_hit_cylinder_from_inside);
	RUN_TEST(should_hit_cylinder_tangent);
	RUN_TEST(should_hit_cylinder_at_oblique_angle);
	RUN_TEST(should_miss_cylinder_above_height);
	RUN_TEST(should_hit_top_cap_from_above);
	RUN_TEST(should_hit_bottom_cap_from_below);
	RUN_TEST(should_miss_cap_outside_radius);
	RUN_TEST(should_normalize_cylinder_axis);
	RUN_TEST(should_hit_horizontal_cylinder_side);
	RUN_TEST(should_hit_cap_when_ray_parallel_to_axis);
	RUN_TEST(should_prefer_cap_over_far_side_root);
}
