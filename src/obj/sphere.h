#ifndef ZIAR_OBJ_SPHERE_H
#define ZIAR_OBJ_SPHERE_H

#include "geom/vector.h"
#include "geom/ray.h"

typedef struct sphere {
  vector sp_pos; /** Sphere position. */
  float  sp_rad; /** Sphere radius.   */
} sphere;

/* Ray/sphere intersection. */
void sphere_intersect(float* t, const sphere* s, const ray* r);
void sphere_normal(vector* n, const sphere* s, const vector* p);

#endif
