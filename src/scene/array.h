#ifndef ZIAR_SCENE_ARRAY_H
#define ZIAR_SCENE_ARRAY_H

#include "geom/ray.h"
#include "geom/isect.h"
#include "obj/object.h"

/// Traverse an array of objects and find the closest intersection.
/// @param[out] i     object intersection
/// @param[in]  objs  array of objects
/// @param[in]  nobjs length of the object array
/// @param[in]  r     intersecting ray
void scene_array_intersect(
        isect*  restrict i,
  const object* restrict objs,
  const size_t           nobjs,
  const ray*    restrict r);

#endif
