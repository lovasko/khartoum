#ifndef ZIAR_OBJ_SPHERE_H
#define ZIAR_OBJ_SPHERE_H

#include "geom/vector.h"
#include "geom/ray.h"


/// Sphere.
typedef struct sphere {
  vector sp_pos; ///< Position.
  float  sp_rad; ///< Radius.
} sphere;

/// Compute the potential ray/sphere intersection point.
/// @param[out] t ray parameter
/// @param[in]  s sphere
/// @param[in]  r ray
void sphere_intersect(
        float*  restrict t,
  const sphere* restrict s,
  const ray*    restrict r);

/// Compute the normal vector in the point of intersection.
/// @param[out] n normal vector
/// @param[in]  s sphere
/// @param[in]  p intersection point
void sphere_normal(
        vector* restrict n,
  const sphere* restrict s,
  const vector* restrict p);

#endif
