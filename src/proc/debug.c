#include <math.h>
#include <float.h>

#include "proc/debug.h"
#include "geom/isect.h"

void
proc_debug_compute(ray* r, isect* i, vector* c)
{
  float angle;

  if (i->is_t < FLT_MAX) {
    vector_norm(&r->ry_dir);
    vector_norm(&i->is_nor);
    vector_dot(&r->ry_dir, &i->is_nor, &angle);
    vector_repeat(c, fabsf(angle));
  } else {
    vector_repeat(c, 0.0f);
  }
}
