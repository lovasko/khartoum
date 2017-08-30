#ifndef ZIAR_GEOM_ISECT_H
#define ZIAR_GEOM_ISECT_H

#include "geom/vector.h"


/// Intersection between a ray and an object.
typedef struct isect {
  vector is_nor; ///< Normal vector.
  float  is_t;   ///< Ray parameter (point of intersection).
} isect;

#endif
