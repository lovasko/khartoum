#include <math.h>
#include <float.h>

#include "obj/sphere.h"

void
sphere_intersect(sphere* s, ray* r, float* t)
{
  float a;
  float b;
  float c;
  float d;
  float b1;
  float b2;
  float c1;
  float c2;
  float c3;
  float t1;
  float t2;

  *t = 0.0f;
  vector_dot(&a,  &r->ry_dir, &r->ry_dir);
  vector_dot(&b1, &r->ry_dir, &r->ry_ori);
  vector_dot(&b2, &r->ry_dir, &s->sp_pos);
  vector_dot(&c1, &r->ry_ori, &r->ry_ori);
  vector_dot(&c2, &s->sp_pos, &r->ry_ori);
  vector_dot(&c3, &s->sp_pos, &s->sp_pos);

  b = (2.0f * b1) - (2.0f * b2);
  c = c1 - (2.0f * c2) + c3 - (s->sp_rad * s->sp_rad);

  if (a == 0.0f) {
    *t = - c / b;
    return;
  }

  d = b * b - 4.0f * a * c;
  if (d < 0.0f)
    return;

  /* Since the square root of a number is always positive, we can work
   * under the assumption that t2 is less than t1. */
  t1 = (-b + sqrtf(d)) / (2.0f * a);
  t2 = (-b - sqrtf(d)) / (2.0f * a);

  if (t2 > 0.0f) {
    *t = t2;
    return;
  }

  if (t1 > 0.0f) {
    *t = t1;
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
