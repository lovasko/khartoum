#ifndef ZIAR_OBJ_SPHERE_H
#define ZIAR_OBJ_SPHERE_H

#include "geom/vector.h"
#include "geom/ray.h"

/// Sphere geometry.
typedef struct sphere {
  vector sp_pos; ///< Position.
  float  sp_rad; ///< Radius.
} sphere;

/// Compute the potential ray/sphere intersection point.
/// @param[out] t ray parameter
/// @param[in]  s sphere
/// @param[in]  r ray
void sphere_intersect(float* t, const sphere* s, const ray* r);

/// Compute the normal vector in the point of intersection.
/// @param[out] n normal vector
/// @param[in]  s sphere
/// @param[in]  p intersection point
void sphere_normal(vector* n, const sphere* s, const vector* p);

#endif
