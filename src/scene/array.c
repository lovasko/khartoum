#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "geom/ray.h"
#include "obj/object.h"
#include "scene/array.h"

void
scene_array_intersect(isect* i,
                      const object* objs,
                      const size_t nobjs,
                      const ray* r)
{
  size_t k;
  float t;     // Ray intersection parameter.
  size_t oidx; // Intersecting object index.
  vector p;    // Ray intersection point.

  t = 0.0f;
  oidx = 0;

  i->is_t = FLT_MAX;
  for (k = 0; k < nobjs; k++) {
    object_intersect(&t, &objs[k], r);
    if (t > 0.0f && t < i->is_t) {
      oidx = k;
      i->is_t = t;
    }
  }

  if (i->is_t < FLT_MAX) {
    ray_point(&p, r, i->is_t);
    object_normal(&i->is_nor, &objs[oidx], &p);
  }
}
