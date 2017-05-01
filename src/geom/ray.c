#include "geom/ray.h"

void
ray_point(ray* r, float t, vector* p)
{
  vector move;

  vector_copy(p, &r->ry_ori);
  vector_copy(&move, &r->ry_dir);
  vector_mul(&move, t);
  vector_add(p, &move);
}
