#include "obj/object.h"
#include "obj/plane.h"
#include "obj/sphere.h"
#include "obj/triangle.h"

typedef void (*isect_func)(void*,ray*,float*);
typedef void (*norm_func)(void*,vector*,vector*);

void
object_intersect(object* o, ray* r, float* t)
{
  isect_func fns[3] = {
    (isect_func)sphere_intersect,
    (isect_func)plane_intersect,
    (isect_func)triangle_intersect
  };

  fns[o->ob_gt](o->ob_geo, r, t);
}

void
object_normal(object* o, vector* p, vector* n)
{
  norm_func fns[3] = {
    (norm_func)sphere_normal,
    (norm_func)plane_normal,
    (norm_func)triangle_normal,
  };

  fns[o->ob_gt](o->ob_geo, p, n);
}
