#ifndef ZIAR_OBJ_PLANE_H
#define ZIAR_OBJ_PLANE_H

#include "geom/vector.h"
#include "geom/ray.h"

typedef struct plane {
  vector pl_pos; /** Plane position.      */
  vector pl_nor; /** Plane normal vector. */
} plane;

/* Ray/plane intersection. */
void plane_intersect(float* t, const plane* p, const ray* r);
void plane_normal(vector* n, const plane* s, const vector* p);

#endif
