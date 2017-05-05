#include "geom/ray.h"

void
ray_point(ray* r, float t, vector* p)
{
  vector_copy(p, &r->ry_dir);
  vector_mul(p, t);
  vector_add(p, &r->ry_ori);
}
