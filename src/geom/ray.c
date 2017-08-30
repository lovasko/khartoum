#include "geom/ray.h"


void
ray_point(vector* restrict p, const ray* restrict r, const float t)
{
  vector_copy(p, &r->ry_dir);
  vector_mul(p, t);
  vector_add(p, &r->ry_ori);
}
