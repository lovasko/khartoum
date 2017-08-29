#include "obj/object.h"
#include "obj/plane.h"
#include "obj/sphere.h"
#include "obj/triangle.h"

/// Virtual intersection function.
typedef void (*isect_func)(float*,const void*,const ray*);

/// Virtual normal vector computation function.
typedef void (*norm_func)(vector*,const void*,const vector*);

void
object_intersect(float* t, const object* o, const ray* r)
{
  isect_func fns[3] = {
    (isect_func)sphere_intersect,
    (isect_func)plane_intersect,
    (isect_func)triangle_intersect
  };

  fns[o->ob_gt](t, o->ob_geo, r);
}

void
object_normal(vector* n, const object* o, const vector* p)
{
  norm_func fns[3] = {
    (norm_func)sphere_normal,
    (norm_func)plane_normal,
    (norm_func)triangle_normal,
  };

  fns[o->ob_gt](n, o->ob_geo, p);
}
