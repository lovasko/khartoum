#ifndef ZIAR_OBJ_OBJECT_H
#define ZIAR_OBJ_OBJECT_H

#include "geom/ray.h"
#include "geom/vector.h"

#define OBJ_SPHERE   0
#define OBJ_PLANE    1
#define OBJ_TRIANGLE 2

/// Generic interface for all geometry objects.
typedef struct object {
  void* ob_geo; ///< Geometry.
  void* ob_mat; ///< Material.
  int   ob_gt;  ///< Geometry type.
  int   ob_mt;  ///< Material type.
} object;

/// Object/ray intersection.
/// @param[out] t ray parameter
/// @param[in]  o object
/// @param[in]  r ray
void object_intersect(
        float*  restrict t,
  const object* restrict o,
  const ray*    restrict r);

/// Intersection normal computation.
/// @param[out] n normal vector
/// @param[in]  o object
/// @param[in]  p point of intersection
void object_normal(
        vector* restrict n,
  const object* restrict o,
  const vector* restrict p);

#endif
