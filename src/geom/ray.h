#ifndef ZIAR_GEOM_RAY_H
#define ZIAR_GEOM_RAY_H

#include "geom/vector.h"

typedef struct ray {
  vector ry_ori; /**< Ray origin.    */
  vector ry_dir; /**< Ray direction. */
} ray;

/** Get a point along the ray.
  *
  * @param[out] p resulting point
  * @param[in]  r ray
  * @param[in]  t direction multiplier
**/
void ray_point(vector* p, const ray* r, const float t);

#endif
