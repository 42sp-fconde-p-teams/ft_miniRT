#include "./tests.h"
#include "../includes/miniRT.h"

// Raio reto contra plano perpendicular ao Z, com plano em z=5.
// t = 5 - 0 = 5.
int	should_hit_plane_straight_on(void)
{
	t_plain	plane;
	t_ray	r;
	double	t;

	plane.coord_point = vec3(0, 0, 5);
	plane.vector = vec3(0, 0, 1);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	if (intersect_plane(r, plane, &t) == EXIT_SUCCESS
		&& fabs(t - 5.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Raio paralelo ao plano (direção paralela à normal? Não, perpendicular!).
// Se o plano é XY (normal = +Z), raio na direção X é paralelo ao plano.
int	should_miss_plane_parallel(void)
{
	t_plain	plane;
	t_ray	r;
	double	t;

	plane.coord_point = vec3(0, 0, 5);
	plane.vector = vec3(0, 0, 1);
	r = ray(vec3(0, 0, 0), vec3(1, 0, 0));   // direção X, plano XY
	if (intersect_plane(r, plane, &t) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Plano atrás do raio: t negativo -> falha.
int	should_miss_plane_behind(void)
{
	t_plain	plane;
	t_ray	r;
	double	t;

	plane.coord_point = vec3(0, 0, -5);
	plane.vector = vec3(0, 0, 1);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	if (intersect_plane(r, plane, &t) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Plano inclinado (45°): normal (1,0,1)/sqrt(2). Raio (0,0,1).
// A interseção deve ser em algum t positivo.
int	should_hit_plane_at_angle(void)
{
	t_plain	plane;
	t_ray	r;
	double	t;

	plane.coord_point = vec3(0, 0, 5);
	plane.vector = vec3(1, 0, 1);   // não normalizado, mas o intersect normaliza
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	if (intersect_plane(r, plane, &t) == EXIT_SUCCESS
		&& t > 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Plano enorme (coordenada longe): teste de robustez.
int	should_hit_plane_far_away(void)
{
	t_plain	plane;
	t_ray	r;
	double	t;

	plane.coord_point = vec3(0, 0, 1000);
	plane.vector = vec3(0, 0, 1);
	r = ray(vec3(0, 0, 0), vec3(0, 0, 1));
	if (intersect_plane(r, plane, &t) == EXIT_SUCCESS
		&& fabs(t - 1000.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_hit_plane_straight_on);
	RUN_TEST(should_miss_plane_parallel);
	RUN_TEST(should_miss_plane_behind);
	RUN_TEST(should_hit_plane_at_angle);
	RUN_TEST(should_hit_plane_far_away);
}
