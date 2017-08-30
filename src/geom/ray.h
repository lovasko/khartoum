#ifndef ZIAR_GEOM_RAY_H
#define ZIAR_GEOM_RAY_H

#include "geom/vector.h"


/// Ray.
typedef struct ray {
  vector ry_ori; ///< Point of origin.
  vector ry_dir; ///< Direction.
} ray;

/// Get a point along the ray.
/// @param[out] p point on the ray
/// @param[in]  r ray
/// @param[in]  t ray parameter
void ray_point(vector* restrict p, const ray* restrict r, const float t);

#endif
