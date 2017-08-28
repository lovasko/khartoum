#ifndef ZIAR_OBJ_OBJECT_H
#define ZIAR_OBJ_OBJECT_H

#include "geom/ray.h"
#include "geom/vector.h"

#define OBJ_SPHERE   0
#define OBJ_PLANE    1
#define OBJ_TRIANGLE 2

typedef struct object {
  void* ob_geo; /** Object geometry.      */
  void* ob_mat; /** Object material.      */
  int   ob_gt;  /** Object geometry type. */
  int   ob_mt;  /** Object material type. */
} object;

/* Object/ray intersection. */
void object_intersect(float* t, const object* o, const ray* r);

/* Intersection normal computation. */
void object_normal(vector* n, const object* o, const vector* p);

#endif
