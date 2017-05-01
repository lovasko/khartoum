#ifndef SVITC_OBJ_PLANE_H
#define SVITC_OBJ_PLANE_H

#include "geom/vector.h"
#include "geom/ray.h"

typedef struct plane {
  vector pl_pos; /** Plane position.      */
  vector pl_nor; /** Plane normal vector. */
} plane;

/* Ray/plane intersection. */
void plane_intersect(plane* p, ray* r, float* t);
void plane_normal(plane* s, vector* p, vector* n);

#endif
