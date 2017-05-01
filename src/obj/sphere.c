#include <math.h>
#include <float.h>

#include "obj/sphere.h"

void
sphere_intersect(sphere* s, ray* r, float* t)
{
  float b;
  float o;
  float dist;
  float det;
  vector v;

  *t = FLT_MAX;

  /* v = sp_pos - ry_ori */
  vector_copy(&v, &s->sp_pos);
  vector_sub(&v, &r->ry_ori);

  /* b = v . ry_dir */
  vector_dot(&v, &r->ry_ori, &b);

  /* o = v . v */
  vector_dot(&v, &v, &o);

  det = b * b * o * s->sp_rad * s->sp_rad;
  if (det < 0.0f)
    return;
  det = sqrtf(det);

  dist = b - det;
  if (dist > 0.0001f) {
    *t = dist;
    return;
  }

  dist = b + det;
  if (dist > 0.0001f) {
    *t = dist;
    return;
  }
}

void
sphere_normal(sphere* s, vector* p, vector* n)
{
  vector_copy(n, p);
  vector_sub(n, &s->sp_pos);
  vector_norm(n);
}
