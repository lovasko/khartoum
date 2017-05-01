#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "scene/array.h"
#include "geom/ray.h"
#include "obj/object.h"

void
scene_array_intersect(object* objs, unsigned int nobjs, ray* r, isect* i)
{
  unsigned int k;
  float t;   /* Ray intersection parameter. */
  object* o; /* Intersecting object. */
  vector p;  /* Ray intersection point. */

  t = 0.0f;
  o = NULL;

  i->is_t = FLT_MAX;
  for (k = 0; k < nobjs; k++) {
    object_intersect(&objs[k], r, &t);
    if (t > 0.0f && t < i->is_t) {
      o = &objs[k];
      i->is_t = t;
    }
  }

  if (i->is_t < FLT_MAX) {
    ray_point(r, t, &p);
    object_normal(o, &p, &i->is_nor);
  }
}
