#include "./tests.h"
#include "../includes/miniRT.h"

// Raio reto no centro da esfera: bate em t=4 (centro em z=5, raio=1)
int	should_hit_sphere_straight_on(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_SUCCESS
		&& fabs(distance - 4.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Raio apontando pro lado oposto: não bate
int	should_miss_sphere_pointing_away(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	r = ray(vec3(0, 0, 0), vec3(0, 0, -1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Esfera deslocada no eixo X: raio na direção Z não bate
int	should_miss_sphere_offset_in_x(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(10, 0, 5);
	sphere.diameter = 2.0;
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Raio começando DENTRO da esfera: deve retornar a raiz positiva
int	should_hit_sphere_from_inside(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, 0);
	sphere.diameter = 4.0;
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_SUCCESS
		&& fabs(distance - 2.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Esfera atrás da origem: as duas raízes são negativas, deve falhar
int	should_miss_sphere_behind_origin(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, -5);
	sphere.diameter = 2.0;
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Raio tangente: discriminante = 0, deve bater num único ponto
int	should_hit_sphere_tangent(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	r = ray(vec3(1, 0, 0), vec3(0, 0, 1));

	if (intersect_sphere(r, sphere, &distance) == EXIT_SUCCESS
		&& fabs(distance - 5.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Interseção oblíqua: deve bater em algum t positivo
int	should_hit_sphere_at_oblique_angle(void)
{
	t_sphere	sphere;
	t_ray		r;
	double		distance;

	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	r = ray(vec3(-2, 0, 0), vec3(0.4472, 0, 0.8944));

	if (intersect_sphere(r, sphere, &distance) == EXIT_SUCCESS
		&& distance > 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_hit_sphere_straight_on);
	RUN_TEST(should_miss_sphere_pointing_away);
	RUN_TEST(should_miss_sphere_offset_in_x);
	RUN_TEST(should_hit_sphere_from_inside);
	RUN_TEST(should_miss_sphere_behind_origin);
	RUN_TEST(should_hit_sphere_tangent);
	RUN_TEST(should_hit_sphere_at_oblique_angle);
}
