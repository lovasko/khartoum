#include "geom/ray.h"

void
ray_point(vector* p, const ray* r, const float t)
{
  vector_copy(p, &r->ry_dir);
  vector_mul(p, t);
  vector_add(p, &r->ry_ori);
}
