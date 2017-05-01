#include "obj/object.h"
#include "obj/sphere.h"
#include "obj/plane.h"

void
object_intersect(object* o, ray* r, float* t)
{
  if (o->ob_gt == OBJ_SPHERE)
    sphere_intersect(o->ob_geo, r, t);

  if (o->ob_gt == OBJ_PLANE)
    plane_intersect(o->ob_geo, r, t);
}

void
object_normal(object* o, vector* p, vector* n)
{
  if (o->ob_gt == OBJ_SPHERE)
    sphere_normal(o->ob_geo, p, n);

  if (o->ob_gt == OBJ_PLANE)
    plane_normal(o->ob_geo, p, n);
}
