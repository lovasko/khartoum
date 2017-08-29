#ifndef ZIAR_OBJ_TRIANGLE_H
#define ZIAR_OBJ_TRIANGLE_H

#include "geom/vector.h"
#include "geom/ray.h"

/// Triangle geometry.
typedef struct triangle {
  vector tr_a; ///< Point A.
  vector tr_b; ///< Point B.
  vector tr_c; ///< Point C.
} triangle;

/// Compute the potential ray/triangle intersection point.
/// @param[out] t ray parameter
/// @param[in]  x triangle
/// @param[in]  r ray
void triangle_intersect(float* t, const triangle* x, const ray* r);

/// Compute the normal vector in the point of intersection.
/// @param[out] n normal vector
/// @param[in]  x triangle
/// @param[in]  p intersection point
void triangle_normal(vector* n, const triangle* x, const vector* p);

#endif
