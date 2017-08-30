#ifndef ZIAR_OBJ_PLANE_H
#define ZIAR_OBJ_PLANE_H

#include "geom/vector.h"
#include "geom/ray.h"

/// Infinite plane geometry.
typedef struct plane {
  vector pl_pos; ///< Plane position.
  vector pl_nor; ///< Plane normal vector.
} plane;

/// Compute the potential ray/plane intersection point.
/// @param[out] t ray parameter
/// @param[in]  p plane
/// @param[in]  r ray
void plane_intersect(
        float* restrict t,
  const plane* restrict p,
  const ray*   restrict r);

/// Compute the normal vector in the point of intersection.
/// @param[out] n normal vector
/// @param[in]  s plane
/// @param[in]  p intersection point
void plane_normal(
        vector* restrict n,
  const plane*  restrict s,
  const vector* restrict p);

#endif
