#ifndef ZIAR_PROC_DEBUG_H
#define ZIAR_PROC_DEBUG_H

#include "geom/isect.h"
#include "geom/ray.h"
#include "geom/vector.h"

/// Produce the resulting color by computing the cosine of an angle between
/// the incoming ray and normal vector in the object intersection.
/// @param[out] c color
/// @param[in]  r ray
/// @param[in]  i object intersection
void proc_debug_compute(vector* c, const ray* r, const isect* i);

#endif
