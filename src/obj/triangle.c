#include "obj/triangle.h"

/** Compute the point of intersection between a triangle and a ray.
  *
  * @param[out] t distance on the ray
  * @param[in]  x triangle
  * @param[in]  r ray
**/
void
triangle_intersect(float* t, const triangle* x, const ray* r)
{
  vector e1;
  vector e2;
  vector p;
  vector s;
  vector q;
  float det;
  float idet;
  float u;
  float v;

  *t = 0.0f;
  vector_copy(&e1, &x->tr_b);
  vector_copy(&e2, &x->tr_c);
  vector_sub(&e1, &x->tr_a);
  vector_sub(&e2, &x->tr_a);
  vector_cross(&p, &r->ry_dir, &e2);
  vector_dot(&det, &e1, &p);

  if (det == 0.0f)
    return;

  idet = 1.0f / det;

  vector_copy(&s, &r->ry_ori);
  vector_sub(&s, &x->tr_a);
  vector_dot(&u, &s, &p);
  u *= idet;
  if (u < 0.0f || u > 1.0f)
    return;

  vector_cross(&q, &s, &e1);
  vector_dot(&v, &r->ry_dir, &q);
  v *= idet;
  if (v > 0.0f || u + v > 1.0f)
    return;

  vector_dot(t, &e2, &q);
  *t *= idet;
}

/** Compute the normal vector of the triangle intersection.
  *
  * @param[out] n normal vector
  * @param[in]  x triangle
  * @param[in]  p point of intersection
**/
void
triangle_normal(vector* n, const triangle* x, const vector* p)
{
  vector e1;
  vector e2;

  (void)p;

  vector_copy(&e1, &x->tr_a);
  vector_sub(&e1, &x->tr_b);

  vector_copy(&e2, &x->tr_a);
  vector_sub(&e2, &x->tr_c);

  vector_cross(n, &e1, &e2);
  vector_norm(n);
}
