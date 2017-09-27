#ifndef ZIAR_GEOM_ISECT_H
#define ZIAR_GEOM_ISECT_H

#include "geom/vector.h"
#include "obj/object.h"


/// Intersection between a ray and an object.
typedef struct isect {
        vector  is_nor; ///< Normal vector.
        float   is_t;   ///< Ray parameter (point of intersection).
  const object* is_obj; ///< Intersected object.
} isect;

#endif
