#include <math.h>
#include <float.h>

#include "geom/isect.h"
#include "proc/debug.h"

void
proc_debug_compute(ray* r, isect* i, vector* c)
{
  float x;

  if (i->is_t < FLT_MAX) {
    vector_dot(&x, &r->ry_dir, &i->is_nor);
    vector_repeat(c, fabsf(x));
  } else {
    vector_repeat(c, 0.0f);
  }
}
