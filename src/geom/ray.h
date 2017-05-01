#ifndef SVITC_GEOM_RAY_H
#define SVITC_GEOM_RAY_H

#include "geom/vector.h"

typedef struct ray {
  vector ry_ori; /** Ray origin.    */
  vector ry_dir; /** Ray direction. */
} ray;

/* Get a point along the ray. */
void ray_point(ray* r, float t, vector* p);

#endif
