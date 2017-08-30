#include <math.h>

#include "geom/vector.h"


void
vector_init(vector* v, const float x, const float y, const float z)
{
  v->vc_x = x;
  v->vc_y = y;
  v->vc_z = z;
}

void
vector_repeat(vector* v, const float xyz)
{
  v->vc_x = xyz;
  v->vc_y = xyz;
  v->vc_z = xyz;
}

void
vector_copy(vector* restrict dst, const vector* restrict src)
{
  dst->vc_x = src->vc_x;
  dst->vc_y = src->vc_y;
  dst->vc_z = src->vc_z;
}

void
vector_add(vector* restrict v, const vector* restrict u)
{
  v->vc_x += u->vc_x;
  v->vc_y += u->vc_y;
  v->vc_z += u->vc_z;
}

void
vector_sub(vector* restrict v, const vector* restrict u)
{
  v->vc_x -= u->vc_x;
  v->vc_y -= u->vc_y;
  v->vc_z -= u->vc_z;
}

void
vector_mul(vector* v, const float s)
{
  v->vc_x *= s;
  v->vc_y *= s;
  v->vc_z *= s;
}

void
vector_norm(vector* v)
{
  float f;

  f = 1.0f
    / sqrtf(v->vc_x * v->vc_x
          + v->vc_y * v->vc_y
          + v->vc_z * v->vc_z);

  vector_mul(v, f);
}

void
vector_dot(
        float*  restrict d,
  const vector* restrict v,
  const vector* restrict u)
{
  *d = v->vc_x * u->vc_x
     + v->vc_y * u->vc_y
     + v->vc_z * u->vc_z;
}

void
vector_cross(
        vector* restrict c,
  const vector* restrict v,
  const vector* restrict u)
{
  c->vc_x = v->vc_y * u->vc_z - v->vc_z * u->vc_y;
  c->vc_y = v->vc_z * u->vc_x - v->vc_x * u->vc_z;
  c->vc_z = v->vc_x * u->vc_y - v->vc_y * u->vc_x;
}
