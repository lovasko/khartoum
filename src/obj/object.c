#include "obj/object.h"
#include "obj/plane.h"
#include "obj/sphere.h"
#include "obj/triangle.h"

/// Virtual intersection function.
typedef void (*isect_func)(
        float* restrict,
  const void*  restrict,
  const ray*   restrict);

/// Virtual normal vector computation function.
typedef void (*norm_func)(
        vector* restrict,
  const void*   restrict,
  const vector* restrict);

void
object_intersect(
        float*  restrict t,
  const object* restrict o,
  const ray*    restrict r)
{
  static const isect_func fns[] = {
    (isect_func)sphere_intersect,
    (isect_func)plane_intersect,
    (isect_func)triangle_intersect
  };

  fns[o->ob_gt](t, o->ob_geo, r);
}

void
object_normal(
        vector* restrict n,
  const object* restrict o,
  const vector* restrict p)
{
  static const norm_func fns[] = {
    (norm_func)sphere_normal,
    (norm_func)plane_normal,
    (norm_func)triangle_normal,
  };

  fns[o->ob_gt](n, o->ob_geo, p);
}
