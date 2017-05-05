#ifndef ZIAR_GEOM_RAY_H
#define ZIAR_GEOM_RAY_H

#include "geom/vector.h"

typedef struct ray {
  vector ry_ori; /**< Ray origin.    */
  vector ry_dir; /**< Ray direction. */
} ray;

/** Get a point along the ray.
  *
  * @param[in]  r ray
  * @param[in]  t direction multiplier
  * @param[out] p resulting point
**/
void ray_point(ray* r, float t, vector* p);

#endif
