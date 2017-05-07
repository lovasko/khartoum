#ifndef ZIAR_OBJ_OBJECT_H
#define ZIAR_OBJ_OBJECT_H

#include "geom/ray.h"
#include "geom/vector.h"

#define OBJ_SPHERE 0
#define OBJ_PLANE  1

typedef struct object {
  void* ob_geo; /** Object geometry.      */
  void* ob_mat; /** Object material.      */
  int   ob_gt;  /** Object geometry type. */
  int   ob_mt;  /** Object material type. */
} object;

/* Object/ray intersection. */
void object_intersect(object* o, ray* r, float* t);

/* Intersection normal computation. */
void object_normal(object* o, vector* p, vector* n);

#endif
